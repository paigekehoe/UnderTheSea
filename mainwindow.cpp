#include "mainwindow.h"
using namespace std;

//ISSUES TO BE FIXED
	//scrolling - weird;
	//not getting first thing entered in QLineEdit? weird also could
		//work on connecting enter - thats annoying
	//deleting items that go off screen and fixing lives
	//Shark movement == weird!!! ew fix.
	//connect game over
	// FIX message box for entering name
	// TRIG FOR SHARK FUNCTION

MainWindow::MainWindow()
{		level=1;
		score=0;
		count=0;
		lives=5;
		game_in_play =false;
		scene = new QGraphicsScene(0, 0, WINDOW_MAX_X*2+100, WINDOW_MAX_Y*2+100);
		//creating a new graphics scene
    view = new QGraphicsView();// scene );
    view->setFixedSize( WINDOW_MAX_X*2, WINDOW_MAX_Y*2 );
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setSceneRect(50, 50, WINDOW_MAX_X*2, WINDOW_MAX_Y*2);
    mainW = new QMainWindow;
    mainW->setCentralWidget(view);
    mainW->setWindowTitle("Under The Sea");
    
    //MAKE BACKGROUND WITH THING
    QPixmap back("water.jpg");
    //createStartScreen();
     createStartArea();
    //graphicsView->setAlignment( Qt::AlignLeft | Qt::AlignTop
    //setSceneRect( 0, 0, width, height ); 
    //QPainter *p;
    //p->drawPixMap(QRect(0,0,WINDOW_MAX_X*2, WINDOW_MAX_Y*2, back);
    scene->setBackgroundBrush(back.scaled(WINDOW_MAX_X*2+100, WINDOW_MAX_Y*2+100, Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
    view->setScene(scene);
    //scene->addItem
    //scene->addWidget(w);
    createTitle();
    //mainW->setDockNestingEnabled(true);
    mainW->addDockWidget(Qt::TopDockWidgetArea, titleArea);
    //menu->move(100, 200);
    createMenuArea();
    mainW->addDockWidget(Qt::BottomDockWidgetArea, menuArea);
    scene->addWidget(welcome);
    welcome->move(250, 100);
   
    //mainW->addDockWidget(Qt::TopDockWidgetArea, scoreArea);
    
    connect(start, SIGNAL(clicked()), this, SLOT(startGame()));
    connect(pause, SIGNAL(clicked()), this, SLOT(pauseGame()));
    connect(stop, SIGNAL(clicked()), this, SLOT(newGame()));
    connect(quit, SIGNAL(clicked()), this, SLOT(quitGame()));
		connect(this, SIGNAL(death()), this, SLOT(gameOver()));
		connect(player_name, SIGNAL(returnPressed()), this, SLOT(startGame()));

		}

MainWindow::~MainWindow()
{
	delete scene;
	delete view;
}

void MainWindow::createTitle(){
	titleArea = new QDockWidget;
	menu = new QWidget;
	player_name = new QLineEdit;  //// make start menu
	QLabel* title = new QLabel(this);
	name_label = new QLabel(this);
	//QLabel* instructions = new QLabel(this);
	const QPixmap picture("UnderTheSea.png");
	title->setPixmap(picture);
	//title->setMask(picture.mask());
	title->setAlignment(Qt::AlignTop | Qt::AlignCenter);
	
	name_label->setText("Input player name and press Start to play. Good Luck!");
	name_label->setAlignment(Qt::AlignCenter | Qt::AlignCenter);
	//instructions->setText("Input player name and press Start to play. Good Luck!");
	QLabel * playerName = new QLabel("Name: ", this);
	playerName->setBuddy(player_name);
	QVBoxLayout *layout = new QVBoxLayout;
	layout->addWidget(title);
	layout->addWidget(name_label);
	//layout->addWidget(instructions);
	menu->setLayout(layout);
	titleArea->setWidget(menu);
	titleArea->setFeatures(QDockWidget::NoDockWidgetFeatures);
	titleArea->show();
	QString tempStr = player_name->text();
	if(tempStr==""){
		//do nothing
	}

}

void MainWindow::createMenuArea(){
		menuArea = new QDockWidget(this);
		QWidget *holder = new QWidget;	
    start = new QPushButton("&Start");
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
		//QWidget *holder = new QWidget;	
		//QHBoxLayout *layout = new QHBoxLayout;
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
  	/*holder->setLayout(layout);
  	scoreArea->setWidget(holder);
  	scoreArea->setFeatures(QDockWidget::NoDockWidgetFeatures);
    scoreArea->show();*/
    
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
		//welcome = new QDockWidget;
		welcome = new QWidget;
		w = new QLabel(this);
		i = new QLabel(this);
		const QPixmap welcome_screen("welcome.png");
		w->setPixmap(welcome_screen);
		const QPixmap instructions("instructions.png");
		i->setPixmap(instructions);
		i->setAlignment(Qt::AlignCenter | Qt::AlignCenter);
		//scene->addWidget(welcome);
		player_name = new QLineEdit();
		
// NEED TO FIGURE OUT HOW TO CONNECT ENTER W/O SEG FALUTIN
		
		layout->addWidget(w);
		layout->addWidget(player_name);
		layout->addWidget(i);
		welcome->setLayout(layout);
		welcome->show();
		
//WAgksndbm,f
		
}
void MainWindow::show(){
	mainW->show();
	//showing all this beautiful code to the user
}

void MainWindow::startGame(){
	level=1;
	lives=5;
	score=0;
	count=0;
	level_label->setNum(level);
	//SOMETIMES DOES NOT CATCH TEXT?? WHY
	string name;
	QString temp =player_name->text();
	name= temp.toStdString();
	if(name==" "){
		temp= player_name->text();
		name=temp.toStdString();
		if(name==""){
		QMessageBox error;
		error.setText("Please input user name!");
		error.exec();
		delete welcome;
		stopGame();
		return;
		}
	}
	delete welcome;
	on_screen.clear();
	name_label->setText("Player:  " + temp);
	//sharks.clear();
	game_in_play = true;
	cout << "start game" << endl;
	mermaid = new Mermaid;
	scene->addItem(mermaid);
	qreal x = mermaid->pos().x();
	qreal y = mermaid->pos().y();
	mermaid->setFocus();
	scene->setFocusItem(mermaid);//mainW->setFocus(mermaid);
	//view->setFocusPolicy(Qt::NoFocus);
	cout << "making pix maps" << endl;
	shark_pic = new QPixmap("sharky.png");
	bubble_pic = new QPixmap("power.png");
	fire_pic = new QPixmap("fireball.png");
	boat_pic = new QPixmap("hull.png");
	// NEED TO WRITE MOUSE PRESS EVENTS IN SCREEN 
	timer = new QTimer(this);
	timer->setInterval(15);
	connect(timer, SIGNAL(timeout()), this, SLOT(handleTimer()));
	//connect(this, SIGNLA(levelUp()), this, SLOT
	timer->start();
	cout << "Timer started " << endl;
		

	}
	/*while(level==1){
		if(count%100==0){
		Shark *m1 = new Shark;
		scene->addItem(m1);
		//on_screen.push_back(m1);
		}
	
	}
	while(level==2){
	
	}
	while(level==3){
	
	
	}*/


//level up function? to increase velocity of monsters?


void MainWindow::handleTimer(){
	/*cout << "fire" << endl;
		Fire *f = new Fire(fire_pic, 550, 350, mermaid->pos().y());
		f->setVel(2, 2);
		scene->addItem(f);
		on_screen.push_back(f);
		cout << f->pos().x() << " " << f->pos().y() << endl;
		
		QLinkedList<GameItem*>::iterator it;
		for(it=on_screen.begin(); it!=on_screen.end(); ++it){
			(*it)->move();
		}
*/
	cout << " HI!" << endl;
	shark_here = false;
//check for collisions
//collides withssssss
		//boat
		//shark
		//fire
		//bubble
		int sharkVel;
		int bubbleVelX, bubbleVelY;
		int boatVelY;
		int fireVelY, fireVelX;
		
	if(count==0){
		sharkVel=1;
		bubbleVelX=2;
		bubbleVelY=2;
		boatVelY=1;
		fireVelY=1;
		fireVelX=1;
	}
	//have everything move do move functions
	if(count==1200){
			sharkVel=2;
		bubbleVelX=2;
		bubbleVelY=2;
		boatVelY=2;
		fireVelY=1;
		fireVelX=1;
		levelUp();
	//emit level up?
		//set velocities
		//every certain number on counter appears sharks and
			//more sparse appear boats
			//bubbles every in a blue moon
			QPixmap *tiki_pic=new QPixmap("tiki.png");
			tiki = new Tiki(tiki_pic, 550, 350);
			scene->addItem(tiki);
	}
	if(count==2900){
		sharkVel=4;
		bubbleVelX=2;
		bubbleVelY=2;
		boatVelY=3;
		fireVelY=2;
		fireVelX=2;
		levelUp();
		//reset velocities
				//tiki man appears
				
			//velocity is incremented for boats and sharks
			//bubbles more often
	}
	if(count==6000){
		sharkVel=7;
		bubbleVelX=3;
		bubbleVelY=3;
		boatVelY=4;
		fireVelY=4;
		fireVelX=4;
		levelUp();
		//velocity increases on boats, sharks, and bullets
	}	
		
	if(count%200==0){ // changed from 200 to 700
		int createS =rand()%5;
		switch(createS){
			case 0:{
				Shark *s1 = new Shark(shark_pic, 900, rand()%450, 50, mermaid->y_);
				scene->addItem(s1);
				//sharks.push_back(s1);
				on_screen.push_back(s1);
				s1->setVel(sharkVel);
				shark_here = true;
				break;}
			case 1:{
				Shark *s4 = new Shark(shark_pic,900, rand()%450, 50, mermaid->y_);
				scene->addItem(s4);
				//sharks.push_back(s4);
				on_screen.push_back(s4);
				s4->setVel(sharkVel);
				shark_here = true;
				break;
				}
			case 2:{
				Shark *s2 = new Shark(shark_pic, 900, rand()%450, 50, mermaid->y_);
				scene->addItem(s2);
				//sharks.push_back(s2);
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
				Bubble *b1 = new Bubble(bubble_pic, 700, rand()%450);
				scene->addItem(b1);
				on_screen.push_back(b1);
				b1->setVel(bubbleVelX, bubbleVelY);
				break;	
			}
		}
	}
	cout << "outch" << endl;
	if(level>=2&&count%70==0){
		//cout << "in here! - fire" << endl;
		//shoot fire!
//		cout << "mermaid pos " << mermaid->pos().y() << endl;
		Fire *f = new Fire(fire_pic, 540.000, 380.000, mermaid->pos().y());
		scene->addItem(f);
		on_screen.push_back(f);
		f->setVel(fireVelX, fireVelY);
	}
	//if(on_screen->empty()==false){
		QLinkedList<GameItem*>::iterator it;
		for(it=on_screen.begin(); it!=on_screen.end(); ++it){
				(*it)->move(); //should set goals be before move?
				(*it)->setGoals(50, mermaid->y_, count);
				if((*it)->collidesWithItem(mermaid)){
					//timer->stop();
					if((*it)->isBubble==true){
							gainLife();
							scoreFunct(10);
					}
					else{
						loseLife();}
					scene->removeItem(*it);
					it = on_screen.erase(it);}
			}  /*
					if((*it)->isBubble==true){ // if it is a bubble? could make a b function for all
						//also could make a bool for x is positive?? that would be cool
						gainLife();
						scoreFunct(10);
					}
					else{
						//could remove the moster from the screen
						if((*it)->isShark==true){
							// remove from screen and take off shark sharks
							//scene->removeItem(*it);
							//sharks.erase(it);}
						//it=on_screen.erase(it);
						loseLife();
					}			}
		/*if(count%15==0){
		QLinkedList<GameItem*>::iterator it;
		for(it=on_screen.begin(); it!=on_screen.end(); ++it){
				(*it)->setGoals(50, mermaid->pos().y());
			}
	}*/


cout << "hither! " << endl;

	QLinkedList<GameItem*>::iterator it3;
	it3=on_screen.begin();
	while(it3!=on_screen.end()){
		if((*it3)->onScreen()==false){
				scene->removeItem(*it3);
				it3= on_screen.erase(it3);
				//++it; //could be wrong
				// remove from linked list and delete
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
	if(count%40==0){
		scoreFunct(1);
	}
	count++;
	score_label->setNum(score);
	lives_label->setNum(lives);
	cout << "done" << endl;
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
					scoreFunct(10);
					cout << "its a bub" << endl;
	}
	else{
		loseLife();
		cout << "ope its not" << endl;
					//could remove the moster from the screen
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
	//NEED TO UPDATE score print out on scene
}

void MainWindow::levelUp(){
	level+=1;
	level_label->setNum(level);
}

void MainWindow::gameOver(){
	QMessageBox loser;
	loser.setText("GAME OVER. you lose :(");
	QString str = QString::number(score);
	QString str1 = "Score: " + str;
	loser.setInformativeText(str1);
	//QPushButton* r= new QPushButton("Resume");
	QPushButton* q = new QPushButton("Quit Game");
	QPushButton* n = new QPushButton("New Game");
	loser.addButton(n, QMessageBox::RejectRole);
	loser.addButton(q, QMessageBox::RejectRole);
	// | QMessageBox::New);
	loser.setDefaultButton(q);
	connect(q, SIGNAL(clicked()), this, SLOT(quitGame()));
	// CONNECT START GAME
	connect(n, SIGNAL(clicked()), this, SLOT(newGame()));
	loser.exec();
}

void MainWindow::pauseGame(){
// NEEDS TO BE FIXED
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
	// CONNECT START GAME
	connect(n, SIGNAL(clicked()), this, SLOT(newGame()));
	connect(r, SIGNAL(clicked()), this, SLOT(resumeTime()));
	pause.exec();
	
}

void MainWindow::stopGame(){
	scene->clear();
	createStartArea();
	scene->addWidget(welcome);
	welcome->move(250, 100);
	game_in_play=false;
	cout << "stop game" << endl;
}

void MainWindow::newGame(){
	scene->clear();
	delete timer;
	//sharks.clear();
	on_screen.clear();
	stopGame();

}
void MainWindow::quitGame(){
	//quitting game
	delete timer;
	QApplication::quit();
	//BYE BYE
}

void MainWindow::keyPressEvent(QKeyEvent *k){
	if(game_in_play==true){
		mermaid->keyPressEvent(k);
	}
}

void MainWindow::mousePressEvent(QMouseEvent *e){
	cout << "in mouse press event" << endl;
	return;
}

void MainWindow::resumeTime(){
	timer->start();
}
