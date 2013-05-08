#include "mainwindow.h"
using namespace std;


MainWindow::MainWindow()
{		//initializing all gameplay values
		level=1;
		score=0;
		count=0;
		lives=5;
		repeat=false;
		game_in_play =false;
		
		ifstream input("scores.txt");
		string tester;
		input>>tester;	
		if(tester==""){ // checking to see if high scores already exist
		  firstGame=true;
		}
		else//high scores exist for the game, so it's not the first play
		  firstGame=false;
		  
		scene = new QGraphicsScene(0, 0, WINDOW_MAX_X*2+100, WINDOW_MAX_Y*2+100);
		//creating a new graphics scene
    view = new QGraphicsView();
    view->setFixedSize( WINDOW_MAX_X*2, WINDOW_MAX_Y*2 );
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setSceneRect(50, 50, WINDOW_MAX_X*2, WINDOW_MAX_Y*2);
    
   	//main window where all user interaction will occur
    mainW = new QMainWindow;
    mainW->setCentralWidget(view);
    mainW->setWindowTitle("Under The Sea");
    
    //MAKING BACKGROUND
    QPixmap back("water.jpg");
    createStartArea(); // creating start screen
    scene->setBackgroundBrush(back.scaled(WINDOW_MAX_X*2+100, WINDOW_MAX_Y*2+100, Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
    view->setScene(scene);
    
    createTitle(); // making the title area
    mainW->addDockWidget(Qt::TopDockWidgetArea, titleArea);
    createMenuArea(); // making the menu area w/ the push buttons
    mainW->addDockWidget(Qt::BottomDockWidgetArea, menuArea);
    scene->addWidget(welcome);
    welcome->move(250, 50);//centering welcome screen
    
    //connecting all of the pushbuttons and signals
    connect(start, SIGNAL(clicked()), this, SLOT(startGame()));
    connect(pause, SIGNAL(clicked()), this, SLOT(pauseGame()));
    connect(stop, SIGNAL(clicked()), this, SLOT(newGame()));
    connect(quit, SIGNAL(clicked()), this, SLOT(quitGame()));
		connect(this, SIGNAL(death()), this, SLOT(gameOver()));
		connect(player_name, SIGNAL(returnPressed()), this, SLOT(startGame()));
		delete welcome;
		stopGame();
	
}

MainWindow::~MainWindow()
{
	//cleaning up
	delete scene;
	delete view;
}

void MainWindow::createTitle(){
	//making a dock widget and adding the menu widget with set layout
	//and added labels for the top area of the mainwindow
	titleArea = new QDockWidget;
	menu = new QWidget;
	player_name = new QLineEdit;  
	QLabel* title = new QLabel(this);
	name_label = new QLabel(this);
	//title picture
	const QPixmap picture("UnderTheSea.png");
	title->setPixmap(picture);
	title->setAlignment(Qt::AlignTop | Qt::AlignCenter);
	
	name_label->setText("Input player name and press Start to play. Good Luck!");
	name_label->setAlignment(Qt::AlignCenter | Qt::AlignCenter);
	//making the layout and adding the labels to it
	QVBoxLayout *layout = new QVBoxLayout;
	layout->addWidget(title);
	layout->addWidget(name_label);
	menu->setLayout(layout);
	titleArea->setWidget(menu);
	titleArea->setFeatures(QDockWidget::NoDockWidgetFeatures);
	titleArea->show();
}

void MainWindow::createMenuArea(){
	//making all of the pushbuttons to control gameplay
	//making the lives, levels, and score display labels
		menuArea = new QDockWidget(this);
		QWidget *holder = new QWidget;	
		//start button
    start = new QPushButton("&Start/Restart");
   	start->setFixedHeight(40);
   	start->setFixedWidth(160);
   	//pause button
    pause = new QPushButton("&Pause");
    pause->setFixedHeight(40);
    pause->setFixedWidth(160);
    //stop button
    stop = new QPushButton("End Game");
   	stop->setFixedHeight(40);
   	stop->setFixedWidth(160);
   	//quit button
 		quit = new QPushButton("&Quit");
 		quit->setFixedHeight(40);
 		quit->setFixedWidth(160);
 		//Adding buttons to a grid layout
    QGridLayout *layout = new QGridLayout;
    scoreArea = new QDockWidget(this);
    //lable to display levels
		level_label = new QLabel(this);
		QLabel* l = new QLabel(this);
		l->setText("Level: ");
		level_label->setNum(level); 
    layout->addWidget(l, 0, 0, Qt::AlignLeft);
    layout->addWidget(level_label, 0, 1, Qt::AlignLeft);
    //label to display lives
    QLabel* v = new QLabel(this);
    v->setText("Lives: ");
    lives_label= new QLabel(this);
    lives_label->setNum(lives);
    layout->addWidget(v, 0, 2, Qt::AlignLeft);
    layout->addWidget(lives_label, 0, 3,Qt::AlignLeft);
    //label to display score
    QLabel *s = new QLabel(this);
    s->setText("Score: ");
    score_label = new QLabel(this);
    score_label->setNum(score);
    //adding all of these widgets and buttons to the layout
    layout->addWidget(s, 0, 5, Qt::AlignLeft);
    layout->addWidget(score_label, 0, 6, Qt::AlignLeft);     
    layout->addWidget(start, 1, 0, Qt::AlignCenter);
    layout->addWidget(pause, 1, 2, Qt::AlignCenter);
    layout->addWidget(stop, 1, 4, Qt::AlignCenter);
    layout->addWidget(quit, 1, 6, Qt::AlignCenter); 
    //setting the layout of the widget that will be added to the dock widget
  	holder->setLayout(layout);
  	//adding place holder widget to dock widget
  	menuArea->setWidget(holder);
  	menuArea->setFeatures(QDockWidget::NoDockWidgetFeatures);
    menuArea->show();
}

void MainWindow::createStartArea(){
		//creating the starting welcome screen that holds the instructions
		//and a lineEdit for a user to input his or her name
		QVBoxLayout * layout = new QVBoxLayout;
		welcome = new QWidget;
		w = new QLabel(this);
		i = new QLabel(this);
		//welcome picture
		const QPixmap welcome_screen("welcome.png");
		w->setPixmap(welcome_screen);
		//picture of instructions
		const QPixmap instructions("instructions.png");
		i->setPixmap(instructions);
		i->setAlignment(Qt::AlignCenter | Qt::AlignCenter);
		//line edit for the player to type his or her name in
		player_name = new QLineEdit();
		//adding these widgets to the Vbox layout
		layout->addWidget(w);
		layout->addWidget(player_name);
		layout->addWidget(i);
		//setting the layout of the parent widget
		welcome->setLayout(layout);
		welcome->show();
		
		
}
void MainWindow::show(){
	mainW->show();
	//showing all this beautiful code to the user
}

void MainWindow::startGame(){
	if(game_in_play==true){
		//restarting the game with the same user
		//cleaning everything up
		delete timer;
		scene->clear(); 
		on_screen.clear(); 
		game_in_play=false;
		repeat=true;
		//starting fresh
		startGame();
		return;
	}
	//starting the game from scratch
	QPixmap back1("water1.jpg");
  scene->setBackgroundBrush(back1.scaled(WINDOW_MAX_X*2+100, WINDOW_MAX_Y*2+100, Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
	level=1;
	lives=5;
	score=0;
	count=0;
	level_label->setNum(level);
	if(repeat==false){//making sure game is not endlessly restarting
		if(player_name->text()==""){//checking for player name
			if(player_name->text()==""){ // player name is blank
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
		delete welcome; // clearing welcome screen
		on_screen.clear();
		name_label->setText(QString::fromStdString("Player:  " + name));
	}
	
	repeat=false;
	game_in_play = true;
	mermaid = new Mermaid; // creating game player
	scene->addItem(mermaid);
	mermaid->setFocus();
	scene->setFocusItem(mermaid);
	//creating all of the pictures for the monsters
	shark_pic = new QPixmap("sharky.png");
	bubble_pic = new QPixmap("power.png");
	fire_pic = new QPixmap("fireball.png");
	boat_pic = new QPixmap("hull.png"); 
	//making the timer to run game animation and movement
	timer = new QTimer(this);
	timer->setInterval(15);
	connect(timer, SIGNAL(timeout()), this, SLOT(handleTimer()));
	timer->start();// let the fun start	

	}

void MainWindow::handleTimer(){

	shark_here = false;
	if(count==0){ // LEVEL ONE
		sharkVel=1;
		bubbleVelX=2;
		bubbleVelY=2;
		boatVelY=1;
		fireVelY=1;
		fireVelX=1;
	}
	if(count==3200){ //LEVEL TWO
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
	if(count==5000){//LEVEL THREE
		sharkVel=2;
		bubbleVelX=4;
		bubbleVelY=4;
		boatVelY=4;
		fireVelY=2;
		fireVelX=2;
		QPixmap back3("water3.jpg");
    scene->setBackgroundBrush(back3.scaled(WINDOW_MAX_X*2+100, WINDOW_MAX_Y*2+100, Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
		levelUp();
	//set velocities for level		
	//velocity is incremented for boats and sharks
	//bubbles more often
	}
	if(count==6000){//LEVEL FOUR
		sharkVel=4;
		bubbleVelX=3;
		bubbleVelY=3;
		boatVelY=5;
		fireVelY=5;
		fireVelX=5;
		QPixmap back4("water4.jpg");
    scene->setBackgroundBrush(back4.scaled(WINDOW_MAX_X*2+100, WINDOW_MAX_Y*2+100, Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
		levelUp();
		//velocity increases on boats, sharks, bubbles, and bullets
		//should be too fast for user to play for very long
	}	
		
	if(count%140==0){ //randomly generate monsters in the game every 140 counts
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
		//shooting fire! ahh (after level 2, when tikiman comes)
		Fire *f = new Fire(fire_pic, 540.000, 380.000, mermaid->pos().y());
		scene->addItem(f);
		on_screen.push_back(f);
		f->setVel(fireVelX, fireVelY);
	}
	
		QLinkedList<GameItem*>::iterator it;
		//iterating though all of the objects on screen
		for(it=on_screen.begin(); it!=on_screen.end(); ++it){
				(*it)->move(); //move everything on screen
				(*it)->setGoals(50, mermaid->y_, count);
				if((*it)->collidesWithItem(mermaid)){
					//checking for collisions w. mermaid
					if((*it)->isBubble==true){ // if it's a bubble
							gainLife(); // add life
							scoreFunct(100); //add points
					}
					else{ // if it's anything else
						loseLife();
					}
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
	//you're gonna die if you have no lives left
	if(lives==0){
		emit death();
	}
	if(count%10==0){ // you get points for every 10 counts you are alive
		scoreFunct(1);
	}
	count++;
	//updating lables on GUI
	score_label->setNum(score);
	lives_label->setNum(lives);
}

void MainWindow::loseLife(){
	//taking away a life and updating label
	lives-=1;
	lives_label->setNum(lives);
}
void MainWindow::gainLife(){
	//adding life and updating label
	lives+=1;
	lives_label->setNum(lives);
}

void MainWindow::scoreFunct(int points){
	//augmenting score and updating it
	score+=points;
	score_label->setNum(score);
}

void MainWindow::levelUp(){
	//increasing the level and updating label
	level+=1;
	level_label->setNum(level);
}

void MainWindow::gameOver(){
	vector<string> nameVec; // vector of player names
	vector<string> scoreVec;//vector of player scores
	int i=0;//int to track number of scores in file
	int hs =0;// int to tell if score is in top 5
	ifstream scoreFile;
	ofstream scoreFileO;
	if(firstGame==true){ // no one has played yet, so just add score to file
		scoreFileO.open("scores.txt");
		scoreFileO<< name;
		cout << name << endl;
		scoreFileO<< "\n";
		scoreFileO<< score;
		cout << score << endl;
		firstGame=false;
		scoreFileO.close();
	}
	else{//the file has other scores in it
	//we need to iterate through to find where the new one goes
		bool added=false;
		scoreFile.open("scores.txt");
		
		while(!scoreFile.eof()){
			
				string tempstring;
				string tempscore;
				getline(scoreFile, tempstring); // get player name
				getline(scoreFile, tempscore); // get player score
				int intScore = atoi(tempscore.c_str());
				if(added==false){ // new score has not been added yet
					hs++;
					if(intScore<score){ // the new score is greater than the score from the file
							nameVec.push_back(name);
							stringstream convert;
							convert<<score;
							scoreVec.push_back(convert.str());
							added=true;	
					}
				}
				nameVec.push_back(tempstring);//add name from file to name vector
				scoreVec.push_back(tempscore);//add score from file to score vector
				i++;
		}
		
		if(added==false){ // add the score to the bottom of the file if it is the smallest
					nameVec.push_back(name);
					stringstream convert;
					convert<<score;
					scoreVec.push_back(convert.str());
		}
		
		scoreFile.close();	
		//opening the output file to write scores and player names in new order		
		scoreFileO.open("scores.txt");
		int j =0;
		while(j<=i){
				scoreFileO<<nameVec[j] << endl;
				scoreFileO<<scoreVec[j]<<endl;
				j++;
		}
			scoreFileO.close();
	}

	QMessageBox loser;
	loser.setText("GAME OVER. you lose :(");
	QString str = QString::number(score);
	QString str1;
		
	if(hs<=5){//new score is in top 5 scores
			str1 = "NEW HIGH SCORE: " + str + "\n"; 
	}
	else{//new score was not in top 5 - you suck!
			str1 = "Score: " + str;
	}
		
	QString final ="\n HIGH SCORES \n";
	
	scoreFile.open("scores.txt"); // open the file to extract top scores
		
		while(!scoreFile.eof()){
		
			for(int j =0; j<5; j++){
					string tempstr;
					string tempsc;
					getline(scoreFile,tempstr);
					getline(scoreFile, tempsc);
					if(tempstr==""||tempsc==""){
						break;
					}
					final = final+ "\n" + QString::fromStdString(tempstr) + "  " + QString::fromStdString(tempsc);
					//creating the string to add to the final message box
			}
			break;
		}
		
		scoreFile.close();
		
		loser.setInformativeText(str1+final);
		//creating buttons for the message box
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

	if(game_in_play==false){ // check to make sure a game is being played
		return;
	}
	timer->stop();
	QMessageBox pause;
	
	pause.setText("Game is paused");
	pause.setInformativeText("What would you like to do?");
	
	QPushButton* r= new QPushButton("Resume");
	QPushButton* q = new QPushButton("Quit Game");
	QPushButton* n = new QPushButton("New Game");
	//adding buttons to messagebox
	pause.addButton(n, QMessageBox::DestructiveRole);
	pause.addButton(q, QMessageBox::RejectRole);
	pause.addButton(r, QMessageBox::AcceptRole);

	pause.setDefaultButton(r);
	//connecting all of the pushbuttons to appropriate signals
	connect(q, SIGNAL(clicked()), this, SLOT(quitGame()));
	connect(n, SIGNAL(clicked()), this, SLOT(newGame()));
	connect(r, SIGNAL(clicked()), this, SLOT(resumeTime()));
	
	pause.exec();
	
}

void MainWindow::stopGame(){   
 
	if(game_in_play==true){
		scene->clear();
	}
	
	createStartArea();
	scene->addWidget(welcome);
	welcome->move(250, 50);
	game_in_play=false;
	
}

void MainWindow::newGame(){

	scene->clear();
	if(game_in_play==true){
		delete timer;
	}
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
	return; //do nothing! do not want to mess up focus
}

void MainWindow::resumeTime(){
	timer->start();
}

