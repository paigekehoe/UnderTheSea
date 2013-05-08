#include "mainwindow.h"
using namespace std;


MainWindow::MainWindow()
{		level=1;
		score=0;
		count=0;
		lives=5;
		repeat=false;
		game_in_play =false;
		ifstream input("scores.txt");
		string tester;
		input>>tester;
		cout << tester << "<- that should be blank?" <<endl;	
		if(tester==""){
		  firstGame=true;
		}
		else
		  firstGame=false;
		scene = new QGraphicsScene(0, 0, WINDOW_MAX_X*2+100, WINDOW_MAX_Y*2+100);
		//creating a new graphics scene
    view = new QGraphicsView();
    view->setFixedSize( WINDOW_MAX_X*2, WINDOW_MAX_Y*2 );
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setSceneRect(50, 50, WINDOW_MAX_X*2, WINDOW_MAX_Y*2);
    mainW = new QMainWindow;
    mainW->setCentralWidget(view);
    mainW->setWindowTitle("Under The Sea");
    
    //MAKING BACKGROUND
    QPixmap back("water.jpg");
    createStartArea();
    scene->setBackgroundBrush(back.scaled(WINDOW_MAX_X*2+100, WINDOW_MAX_Y*2+100, Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
    view->setScene(scene);
    createTitle();
    mainW->addDockWidget(Qt::TopDockWidgetArea, titleArea);
    createMenuArea();
    mainW->addDockWidget(Qt::BottomDockWidgetArea, menuArea);
    scene->addWidget(welcome);
    welcome->move(250, 50);
    
    connect(start, SIGNAL(clicked()), this, SLOT(startGame()));
    connect(pause, SIGNAL(clicked()), this, SLOT(pauseGame()));
    connect(stop, SIGNAL(clicked()), this, SLOT(newGame()));
    connect(quit, SIGNAL(clicked()), this, SLOT(quitGame()));
		connect(this, SIGNAL(death()), this, SLOT(gameOver()));
		
		connect(player_name, SIGNAL(returnPressed()), this, SLOT(startGame()));
		delete welcome;
		stopGame();
		
//		scoreFile.open("scores.txt");
//		if(scoreFile.is_open()){
//			cout << "file opened" << endl;
//		}
		}

MainWindow::~MainWindow()
{
	delete scene;
	delete view;
}

void MainWindow::createTitle(){
	titleArea = new QDockWidget;
	menu = new QWidget;
	player_name = new QLineEdit;  
	QLabel* title = new QLabel(this);
	name_label = new QLabel(this);

	const QPixmap picture("UnderTheSea.png");
	title->setPixmap(picture);

	title->setAlignment(Qt::AlignTop | Qt::AlignCenter);
	
	name_label->setText("Input player name and press Start to play. Good Luck!");
	name_label->setAlignment(Qt::AlignCenter | Qt::AlignCenter);
	
	QVBoxLayout *layout = new QVBoxLayout;
	layout->addWidget(title);
	layout->addWidget(name_label);
	menu->setLayout(layout);
	titleArea->setWidget(menu);
	titleArea->setFeatures(QDockWidget::NoDockWidgetFeatures);
	titleArea->show();
}

void MainWindow::createMenuArea(){
		menuArea = new QDockWidget(this);
		QWidget *holder = new QWidget;	
    start = new QPushButton("&Start/Restart");
   	start->setFixedHeight(40);
   	start->setFixedWidth(160);
    pause = new QPushButton("&Pause");
    pause->setFixedHeight(40);
    pause->setFixedWidth(160);
    stop = new QPushButton("End Game");
   	stop->setFixedHeight(40);
   	stop->setFixedWidth(160);
 		quit = new QPushButton("&Quit");
 		quit->setFixedHeight(40);
 		quit->setFixedWidth(160);
    QGridLayout *layout = new QGridLayout;
    
    scoreArea = new QDockWidget(this);
		level_label = new QLabel(this);
		QLabel* l = new QLabel(this);
		l->setText("Level: ");
		level_label->setNum(level); 
    layout->addWidget(l, 0, 0, Qt::AlignLeft);
    layout->addWidget(level_label, 0, 1, Qt::AlignLeft);
    QLabel* v = new QLabel(this);
    v->setText("Lives: ");
    lives_label= new QLabel(this);
    lives_label->setNum(lives);
    layout->addWidget(v, 0, 2, Qt::AlignLeft);
    layout->addWidget(lives_label, 0, 3,Qt::AlignLeft);
    QLabel *s = new QLabel(this);
    s->setText("Score: ");
    score_label = new QLabel(this);
    score_label->setNum(score);
    layout->addWidget(s, 0, 5, Qt::AlignLeft);
    layout->addWidget(score_label, 0, 6, Qt::AlignLeft);     
    layout->addWidget(start, 1, 0, Qt::AlignCenter);
    layout->addWidget(pause, 1, 2, Qt::AlignCenter);
    layout->addWidget(stop, 1, 4, Qt::AlignCenter);
    layout->addWidget(quit, 1, 6, Qt::AlignCenter); 
  	holder->setLayout(layout);
  	menuArea->setWidget(holder);
  	menuArea->setFeatures(QDockWidget::NoDockWidgetFeatures);
    menuArea->show();
}

void MainWindow::createStartArea(){
		QVBoxLayout * layout = new QVBoxLayout;
		welcome = new QWidget;
		w = new QLabel(this);
		i = new QLabel(this);
		//scores_button=new QPushButton("Show High Scores");
		const QPixmap welcome_screen("welcome.png");
		w->setPixmap(welcome_screen);
		const QPixmap instructions("instructions.png");
		i->setPixmap(instructions);
		i->setAlignment(Qt::AlignCenter | Qt::AlignCenter);

		player_name = new QLineEdit();
		layout->addWidget(w);
		layout->addWidget(player_name);
		layout->addWidget(i);
		//layout->addWidget(scores_button);
		//connect(scores_button, SIGNAL(clicked()), this, SLOT(showScores()));
		welcome->setLayout(layout);
		welcome->show();
		
		
}
void MainWindow::show(){
	mainW->show();
	//showing all this beautiful code to the user
}

void MainWindow::startGame(){
if(game_in_play==true){
	delete timer;
	scene->clear();
	on_screen.clear();
	game_in_play=false;
	repeat=true;
	startGame();
	return;
}
	QPixmap back1("water1.jpg");
  scene->setBackgroundBrush(back1.scaled(WINDOW_MAX_X*2+100, WINDOW_MAX_Y*2+100, Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
	level=1;
	lives=5;
	score=0;
	count=0;
	level_label->setNum(level);
if(repeat==false){
	if(player_name->text()==""){
		if(player_name->text()==""){
		QMessageBox error;
		error.setText("Please input user name!");
		error.exec();
		delete welcome;
		stopGame();
		return;
		}
	}
	
	QString temp =player_name->text();
	name= temp.toStdString();

	delete welcome;
	on_screen.clear();
	name_label->setText(QString::fromStdString("Player:  " + name));
	}
	repeat=false;
	game_in_play = true;
	mermaid = new Mermaid;
	scene->addItem(mermaid);
	mermaid->setFocus();
	scene->setFocusItem(mermaid);
	shark_pic = new QPixmap("sharky.png");
	bubble_pic = new QPixmap("power.png");
	fire_pic = new QPixmap("fireball.png");
	boat_pic = new QPixmap("hull.png"); 
	timer = new QTimer(this);
	timer->setInterval(15);
	connect(timer, SIGNAL(timeout()), this, SLOT(handleTimer()));
	timer->start();// let the fun start	

	}
	/*while(level==1){
		if(count%100==0){
		Shark *m1 = new Shark;
		scene->addItem(m1);
		//on_screen.push_back(m1);*/


void MainWindow::handleTimer(){

	shark_here = false;
//check for collisions
//collides withssssss
		//boat
		//shark
		//fire
		//bubble
// ALL OF THE VELOCITIES ARE HERE
	if(count==0){
		sharkVel=1;
		bubbleVelX=2;
		bubbleVelY=2;
		boatVelY=1;
		fireVelY=1;
		fireVelX=1;
	}
	if(count==3200){
			sharkVel=1.5;
		bubbleVelX=3;
		bubbleVelY=3;
		boatVelY=3;
		fireVelY=1;
		fireVelX=1;
		QPixmap back2("water2.jpg");
    scene->setBackgroundBrush(back2.scaled(WINDOW_MAX_X*2+100, WINDOW_MAX_Y*2+100, Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
		levelUp();
		//emit level up
		//set velocities
		//every certain number on counter appears sharks and
		//increase speed
		//tiki man appears!
		//bubbles every in a blue moon
			QPixmap *tiki_pic=new QPixmap("tiki.png");
			tiki = new Tiki(tiki_pic, 550, 350);
			scene->addItem(tiki);
	}
	if(count==5000){
		sharkVel=2;
		bubbleVelX=4;
		bubbleVelY=4;
		boatVelY=4;
		fireVelY=2;
		fireVelX=2;
		QPixmap back3("water3.jpg");
    scene->setBackgroundBrush(back3.scaled(WINDOW_MAX_X*2+100, WINDOW_MAX_Y*2+100, Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
		levelUp();
	//reset velocities
	//tiki man appears			
	//velocity is incremented for boats and sharks
	//bubbles more often
	}
	if(count==6000){
		sharkVel=4;
		bubbleVelX=3;
		bubbleVelY=3;
		boatVelY=5;
		fireVelY=5;
		fireVelX=5;
		QPixmap back4("water4.jpg");
    scene->setBackgroundBrush(back4.scaled(WINDOW_MAX_X*2+100, WINDOW_MAX_Y*2+100, Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
		levelUp();
		//velocity increases on boats, sharks, and bullets
	}	
		
	if(count%140==0){ 
		int createS =rand()%5;
		switch(createS){
			case 0:{
				Shark *s1 = new Shark(shark_pic, 900, rand()%450, 50, mermaid->y_);
				scene->addItem(s1);
				on_screen.push_back(s1);
				s1->setVel(sharkVel);
				shark_here = true;
				break;}
			case 1:{
				Shark *s4 = new Shark(shark_pic,900, rand()%450, 50, mermaid->y_);
				scene->addItem(s4);
				on_screen.push_back(s4);
				s4->setVel(sharkVel);
				shark_here = true;
				break;
				}
			case 2:{
				Shark *s2 = new Shark(shark_pic, 900, rand()%450, 50, mermaid->y_);
				scene->addItem(s2);
				on_screen.push_back(s2);
				s2->setVel(sharkVel);
				shark_here = true;
				break;}
			case 3:{
				Boat *bt = new Boat(boat_pic, 900, 50);
				scene->addItem(bt);
				on_screen.push_back(bt);
				bt->setVel(boatVelY);
				break;}
			case 4:{
				Bubble *b1 = new Bubble(bubble_pic, 700, rand()%400+55);
				scene->addItem(b1);
				on_screen.push_back(b1);
				b1->setVel(bubbleVelX, bubbleVelY);
				break;	
			}
		}
	}
	if(level>=2&&count%70==0){
		//shooting fire! ahh
		Fire *f = new Fire(fire_pic, 540.000, 380.000, mermaid->pos().y());
		scene->addItem(f);
		on_screen.push_back(f);
		f->setVel(fireVelX, fireVelY);
	}
		QLinkedList<GameItem*>::iterator it;
		for(it=on_screen.begin(); it!=on_screen.end(); ++it){
				(*it)->move(); //move everything on screen
				(*it)->setGoals(50, mermaid->y_, count);
				if((*it)->collidesWithItem(mermaid)){
					//checking for collisions
					if((*it)->isBubble==true){
							gainLife();
							scoreFunct(10);
					}
					else{
						loseLife();}
					scene->removeItem(*it);
					it = on_screen.erase(it);}
			}

	QLinkedList<GameItem*>::iterator it3;
	it3=on_screen.begin();
	while(it3!=on_screen.end()){
		if((*it3)->onScreen()==false){
				scene->removeItem(*it3);
				it3= on_screen.erase(it3);
			}
		else
			++it3;
	}
	/*if(shark_here==true&&count%10==0){
	int i=0;
		QLinkedList<Shark*>::iterator it2;
		for(it2=sharks.begin(); it2!=sharks.end(); ++it2){
			(*it2)->setGoals(50, mermaid->pos().y()); 
			cout << "sharks FORLOOP!" << endl;
			i++;
		}
		if(i==0){
			shark_here=false;
		}
	}*/                                    
	
	if(lives==0){
		emit death();
	}
	if(count%10==0){
		scoreFunct(1);
	}
	count++;
	score_label->setNum(score);
	lives_label->setNum(lives);
}

void MainWindow::loseLife(){
	lives-=1;
	lives_label->setNum(lives);
}
void MainWindow::gainLife(){
	lives+=1;
	lives_label->setNum(lives);
}

void MainWindow::collision(GameItem *item){
	timer->stop();
	scene->removeItem(item);
	on_screen.removeOne(item);
	if(item->isBubble==true){ // if it is a bubble? could make a b function for all
	//also could make a bool for x is positive?? that would be cool
					gainLife();
					scoreFunct(100);
	}
	else{
		loseLife();
			/*if(item->isShark==true){
				QLinkedList<Shark*>::iterator i;
				i=sharks.begin();
				while( i!=sharks.end()){
						if(&i==&item){
							i=sharks.erase(i);
						}
						else
							++i;
				}*/
					//sharks.removeOne(*it);
			}		
			/*if(sharks.empty()==true){
							shark_here=false;
			}*/	// remove from screen and take off shark sharks
						//scene->removeItem(*it);
						//sharks.erase(it);	
								//it=on_screen.erase(it);		
	timer->start();
}

void MainWindow::scoreFunct(int points){
	score+=points;
	score_label->setNum(score);
}

void MainWindow::levelUp(){
	level+=1;
	level_label->setNum(level);
}

void MainWindow::gameOver(){
	// the high score file
	vector<string> nameList;
	vector<string> scoreList;
	int i=0;
	ifstream scoreFile;
	ofstream scoreFileO;
	if(firstGame==true){
		scoreFileO.open("scores.txt");
		cout << "wowzers" << endl;
		scoreFileO<< name;
		cout << name << endl;
		scoreFileO<< "\n";
		scoreFileO<< score;
		cout << score << endl;
		firstGame=false;
		cout << "closing time" << endl;
		scoreFileO.close();
	}
	else{
		cout << "hi you're dead" << endl;
		bool added=false;
		scoreFile.open("scores.txt");
		cout << "1" << endl;
			while(!scoreFile.eof()){
				cout << "1.5" << endl;
				string tempstring;
				string tempscore;
				getline(scoreFile, tempstring);
				getline(scoreFile, tempscore);
				cout << tempstring << "  " <<tempscore <<endl;
				int intScore = atoi(tempscore.c_str());
				if(added==false){
					if(intScore<score){
							//scoreFile<<name << "\n" << score;
							cout << " you are better than the others" <<endl;
							nameList.push_back(name);
							stringstream convert;
							convert<<score;
							scoreList.push_back(convert.str());
							added=true;	
					}
				}
				nameList.push_back(tempstring);
				scoreList.push_back(tempscore);
				i++;
				cout << "2" << endl;
			}
			if(added==false){
					//scoreFile<<name << " " << score;
					nameList.push_back(name);
					stringstream convert;
					convert<<score;
					scoreList.push_back(convert.str());
					cout << " 2.5" << endl;
					}
				scoreFile.close();//necessary?		
			cout << "ope open again" << endl;
			scoreFileO.open("scores.txt");
			int j =0;
			while(j<=i){
				scoreFileO<<nameList[j] << endl;
				scoreFileO<<scoreList[j]<<endl;
				cout << nameList[i] << "  " << scoreList[j] << endl;
				j++;
			}
			scoreFileO.close();
		}
		//scoreFileO<<name<<"\n"<<score;
		cout << "5" << endl;
		QMessageBox loser;
		loser.setText("GAME OVER. you lose :(");
		QString str = QString::number(score);
		QString str1;
		if(i<5){
			str1 = "NEW HIGH SCORE: " + str; }
		else{
			cout<< "blarg" << endl;
			str1 = "Score: " + str;}
			QString final ="\n HIGH SCORES \n";
			cout << "you go girl" << endl;
			scoreFile.open("scores.txt");
			while(!scoreFile.eof()){
				for(int j =0; j<5; j++){
					string tempstr;
					string tempsc;
					cout << "AHH" << endl;
					getline(scoreFile,tempstr);
					getline(scoreFile, tempsc);
					if(tempstr==""||tempsc==""){
						break;
					}
					final = final+ "\n" + QString::fromStdString(tempstr) + "  " + QString::fromStdString(tempsc);
				}
				break;
			}
			scoreFile.close();
			loser.setInformativeText(str1+final);
		QPushButton* q = new QPushButton("Quit Game");	
		QPushButton* n = new QPushButton("New Game");
		loser.addButton(n, QMessageBox::RejectRole);
		loser.addButton(q, QMessageBox::RejectRole);
		loser.setDefaultButton(q);
		connect(q, SIGNAL(clicked()), this, SLOT(quitGame()));
		connect(n, SIGNAL(clicked()), this, SLOT(newGame()));
		loser.exec();
	}

void MainWindow::pauseGame(){
	if(game_in_play==false){
		return;
	}
	timer->stop();
	QMessageBox pause;
	pause.setText("Game is paused");
	pause.setInformativeText("What would you like to do?");
	QPushButton* r= new QPushButton("Resume");
	QPushButton* q = new QPushButton("Quit Game");
	QPushButton* n = new QPushButton("New Game");
	pause.addButton(n, QMessageBox::DestructiveRole);
	pause.addButton(q, QMessageBox::RejectRole);
	pause.addButton(r, QMessageBox::AcceptRole);
	// | QMessageBox::New);
	pause.setDefaultButton(r);
	connect(q, SIGNAL(clicked()), this, SLOT(quitGame()));
	connect(n, SIGNAL(clicked()), this, SLOT(newGame()));
	connect(r, SIGNAL(clicked()), this, SLOT(resumeTime()));
	pause.exec();
	
}

void MainWindow::stopGame(){    
	if(game_in_play==true){
	scene->clear();}
	createStartArea();
	scene->addWidget(welcome);
	welcome->move(250, 50);
	game_in_play=false;
}

void MainWindow::newGame(){
	scene->clear();
	if(game_in_play==true){
	delete timer;}
	name_label->setText("Input player name and press Start to play. Good Luck!");
	on_screen.clear();
	game_in_play=false;
	stopGame();

}
void MainWindow::quitGame(){
	//quitting game
	if(game_in_play==true){
	delete timer;
	}	
	QApplication::quit();
	//BYE BYE
}

void MainWindow::keyPressEvent(QKeyEvent *k){
	if(game_in_play==true){
		mermaid->keyPressEvent(k);
	}
}

void MainWindow::mousePressEvent(QMouseEvent *e){
	return;
}

void MainWindow::resumeTime(){
	timer->start();
}

void MainWindow::showScores(){}/*
	cout << "in show scores" << endl;
	scene->clear();
	cout << "meg" << endl;
	//delete welcome;
	cout << "blard" << endl;
		QVBoxLayout * layout = new QVBoxLayout;
		scores_widget = new QWidget;
		QLabel *scoreTitle = new QLabel(this);
		QPushButton *back =new QPushButton("back");
		connect(back, SIGNAL(clicked()), this, SLOT(stopGame()));
		const QPixmap scores_pic("scores.png");
		scoreTitle->setPixmap(scores_pic);
		scoreTitle->setAlignment(Qt::AlignCenter | Qt::AlignCenter);
		layout->addWidget(scoreTitle);
		scoreFile.open("scores.txt");
		cout << "opened" << endl;
		if(firstGame!=true){
			while(scoreFile.good()){
				cout << " hey hey hey I am in the file" << endl;
				for(int i=0; i<5; i++){
					cout << " Iteration " << i << endl;
					string tempName;
					int tempScore;
					scoreFile>>tempName;
					scoreFile>>tempScore;
					cout << tempName;
					cout << tempScore;
					QLabel* temp = new QLabel(this);
					stringstream conversion;
					conversion << tempScore;
					string output = tempName + "  " + conversion.str();
					QString qstr = QString::fromStdString(output);
					temp->setText(qstr);
					layout->addWidget(temp);
				}
			}
		}
		cout << " mAHH" << endl;
		//layout->addWidget(scores_button);
		scores_widget->setLayout(layout);
		cout << "hey" << endl;
		scores_widget->show();
		cout << "woow" << endl;
		scene->addWidget(scores_widget);
		cout << " gaga " << endl;
}*/
