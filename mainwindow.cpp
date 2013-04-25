#include "mainwindow.h"
using namespace std;

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
    //view->setSceneRect(QRectF(WINDOW_MAX_X*2, WINDOW_MAX_Y*2));
    mainW = new QMainWindow;
    mainW->setCentralWidget(view);
    mainW->setWindowTitle("Under The Sea");
    
    //MAKE BACKGROUND WITH THING
    QPixmap back("water.jpg");
    //createStartScreen();
     createScoreArea();
    //graphicsView->setAlignment( Qt::AlignLeft | Qt::AlignTop
    //setSceneRect( 0, 0, width, height ); 
    //QPainter *p;
    //p->drawPixMap(QRect(0,0,WINDOW_MAX_X*2, WINDOW_MAX_Y*2, back);
    scene->setBackgroundBrush(back.scaled(WINDOW_MAX_X*2+100, WINDOW_MAX_Y*2+100, Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
    view->setScene(scene);
    //scene->addItem
    scene->addWidget(w);
    scene->addWidget(welcome);
    createStartScreen();
    //mainW->setDockNestingEnabled(true);
    mainW->addDockWidget(Qt::TopDockWidgetArea, titleArea);
    //menu->move(100, 200);
    createMenuArea();
    mainW->addDockWidget(Qt::BottomDockWidgetArea, menuArea);
   
    //mainW->addDockWidget(Qt::TopDockWidgetArea, scoreArea);
    
    connect(start, SIGNAL(clicked()), this, SLOT(startGame()));
    connect(pause, SIGNAL(clicked()), this, SLOT(pauseGame()));
    connect(stop, SIGNAL(clicked()), this, SLOT(stopGame()));
    connect(quit, SIGNAL(clicked()), this, SLOT(quitGame()));
		connect(this, SIGNAL(death()), this, SLOT(gameOver()));
}

MainWindow::~MainWindow()
{
	delete scene;
	delete view;
}

void MainWindow::createStartScreen(){
	titleArea = new QDockWidget;
	menu = new QWidget;
	player_name = new QLineEdit;  //// make start menu
	QLabel* title = new QLabel(this);
	QLabel* subtitle = new QLabel(this);
	QLabel* instructions = new QLabel(this);
	const QPixmap picture("UnderTheSea.png");
	title->setPixmap(picture);
	//title->setMask(picture.mask());
	title->setAlignment(Qt::AlignTop | Qt::AlignCenter);
	subtitle->setText("Input player name and press Start to play. Good Luck!");
	subtitle->setAlignment(Qt::AlignCenter | Qt::AlignCenter);
	//instructions->setText("Input player name and press Start to play. Good Luck!");
	QLabel * playerName = new QLabel("Name: ", this);
	playerName->setBuddy(player_name);
	instructions->setAlignment(Qt::AlignCenter | Qt::AlignCenter);
	QVBoxLayout *layout = new QVBoxLayout;
	layout->addWidget(title);
	layout->addWidget(subtitle);
	//layout->addWidget(instructions);
	menu->setLayout(layout);
	titleArea->setWidget(menu);
	titleArea->setFeatures(QDockWidget::NoDockWidgetFeatures);
	titleArea->show();

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

void MainWindow::createScoreArea(){

		//welcome = new QDockWidget;
		welcome = new QWidget;
		w = new QLabel(this);
		const QPixmap welcome_screen("welcome.png");
		w->setPixmap(welcome_screen);
		//scene->addWidget(welcome);
		player_name = new QLineEdit();
		//welcome->
		//welcome->addItem(w);
		//welcome->addWidget(player_name);
		//welcome->setWidget(holder);
		//welcome->setFeatures(QDockWidget::NoDockWidgetFeatures);
		//welcome->show();
// LEFT OFF HERE MAKING THE WORDS THAT YOU NEED!!!
		/*scoreArea = new QDockWidget(this);
		QWidget *holder = new QWidget;	
		QHBoxLayout *layout = new QHBoxLayout;
		level_label = new QLabel(this);
		QLabel* l = new QLabel(this);
		l->setText("	Level: ");
		level_label->setNum(level); 
    layout->addWidget(l);
    layout->addWidget(level_label);
    QLabel* v = new QLabel(this);
    v->setText("	Lives: ");
    lives_label= new QLabel(this);
    lives_label->setNum(lives);
    layout->addWidget(v);
    layout->addWidget(lives_label);
    QLabel *s = new QLabel(this);
    s->setText("	Score: ");
    score_label = new QLabel(this);
    score_label->setNum(score);
    layout->addWidget(s);
    layout->addWidget(score_label); 
  	holder->setLayout(layout);
  	scoreArea->setWidget(holder);
  	scoreArea->setFeatures(QDockWidget::NoDockWidgetFeatures);
    scoreArea->show();*/
}
void MainWindow::show(){
	mainW->show();
	//showing all this beautiful code to the user
}

void MainWindow::startGame(){
	scene->clear();
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
	fire_pic = new QPixmap("fire.png");
	boat_pic = new QPixmap("hull.png");
	// NEED TO WRITE MOUSE PRESS EVENTS IN SCREEN 
	timer = new QTimer(this);
	timer->setInterval(8);
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
	cout << " HI!" << endl;
	bool shark_here = false;
//check for collisions
//collides withssssss
		//boat
		//shark
		//fire
		//bubble
		int sharkVelX, sharkVelY;
		int bubbleVelX, bubbleVelY;
		int boatVelY;
		int fireVelY, fireVelX;
		
	if(count==0){
	cout << " in if! " << endl;
		sharkVelX=1;
		sharkVelY=1;
		bubbleVelX=2;
		bubbleVelY=2;
		boatVelY=1;
		fireVelY=1;
		fireVelX=1;
	}
	//have everything move do move functions
	if(score==2000){
			sharkVelX=2;
		sharkVelY=2;
		bubbleVelX=2;
		bubbleVelY=2;
		boatVelY=1;
		fireVelY=2;
		fireVelX=2;
		levelUp();
	//emit level up?
		//set velocities
		//every certain number on counter appears sharks and
			//more sparse appear boats
			//bubbles every in a blue moon
	}
	if(score==5000){
		sharkVelX=3;
		sharkVelY=3;
		bubbleVelX=2;
		bubbleVelY=2;
		boatVelY=2;
		fireVelY=3;
		fireVelX=3;
		levelUp();
		//reset velocities
				//tiki man appears
				QPixmap *tiki_pic=new QPixmap("tiki.png");
				tiki = new Tiki(tiki_pic, 550, 350);
				scene->addItem(tiki);
			//velocity is incremented for boats and sharks
			//bubbles more often
	}
	if(score==8000){
		sharkVelX=4;
		sharkVelY=4;
		bubbleVelX=2;
		bubbleVelY=2;
		boatVelY=3;
		fireVelY=4;
		fireVelX=4;
		levelUp();
		//velocity increases on boats, sharks, and bullets
	}	
		
	if(count%200==0){
		cout << "Lets switch" << endl;
		int createS =rand()%6;
		switch(createS){
			case 0:{
				Shark *s1 = new Shark(shark_pic, 900, rand()%500, 50, mermaid->y_);
				scene->addItem(s1);
				sharks.push_back(s1);
				on_screen.push_back(s1);
				s1->setVel(sharkVelX, sharkVelY);
				shark_here = true;
				break;}
			case 1:{
				Bubble *b1 = new Bubble(bubble_pic, 900, rand()%500);
				scene->addItem(b1);
				on_screen.push_back(b1);
				b1->setVel(bubbleVelX, bubbleVelY);
				break;}
			case 2:{
				Shark *s2 = new Shark(shark_pic, 900, rand()%500, 50, mermaid->y_);
				scene->addItem(s2);
				sharks.push_back(s2);
				on_screen.push_back(s2);
				s2->setVel(sharkVelX, sharkVelY);
				shark_here = true;
				break;}
			case 3:{
				Boat *bt = new Boat(boat_pic, 900, 30);
				scene->addItem(bt);
				on_screen.push_back(bt);
				bt->setVel(boatVelY);
				break;}
			case 4:{
				Shark *s3 = new Shark(shark_pic, 900, rand()%500, 50, mermaid->y_);
				scene->addItem(s3);
				sharks.push_back(s3);
				on_screen.push_back(s3);
				s3->setVel(sharkVelX, sharkVelY);
				shark_here = true;
				break;}
			case 5:{
					Shark *s4 = new Shark(shark_pic,900, rand()%500, 50, mermaid->y_);
				scene->addItem(s4);
				sharks.push_back(s4);
				on_screen.push_back(s4);
				s4->setVel(sharkVelX, sharkVelY);
				shark_here = true;
				break;			
			}
			case 6:{
				Shark *s5 = new Shark(shark_pic, 900, rand()%500, 50, mermaid->y_);
				scene->addItem(s5);
				sharks.push_back(s5);
				on_screen.push_back(s5);
				s5->setVel(sharkVelX, sharkVelY);
				shark_here = true;
				break;
			}
		}
	}
	QLinkedList<GameItem*>::iterator it;
	for(it=on_screen.begin(); it!=on_screen.end(); ++it){
	cout << "for loop!" << endl;
			(*it)->move();
			if((*it)->collidesWithItem(mermaid)){
				if((*it)->isBubble==true){ // if it is a bubble? could make a b function for all
					//also could make a bool for x is positive?? that would be cool
					gainLife();
					scoreFunct(100);
				}
				else{
					loseLife();
				}
			}
	}
	for(it=on_screen.begin(); it!=on_screen.end(); ++it){
		if((*it)->onScreen()==false){
				cout << "removing item?" << endl;
				scene->removeItem((*it));
				cout << "ope" << endl;
				on_screen.erase(it);
				cout << "MAH" << endl;
				//++it; //could be wrong
				// remove from linked list and delete
			}
	}
	
	if(shark_here==true&&count%30==0){
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
	}
	if(lives==0){
		emit death();
	}
	if(count%400==0){
		scoreFunct(1);
	}
	count+=1;
	score_label->setNum(score);
	lives_label->setNum(lives);
	cout << "all done!" << endl;
}

void MainWindow::loseLife(){
	lives-=1;
	scoreFunct(-100);
	lives_label->setNum(lives);

}
void MainWindow::gainLife(){
	lives+=1;
	lives_label->setNum(lives);
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
	QPushButton* r= new QPushButton("Resume");
	QPushButton* q = new QPushButton("Quit Game");
	QPushButton* n = new QPushButton("New Game");
	loser.addButton(n, QMessageBox::DestructiveRole);
	loser.addButton(q, QMessageBox::RejectRole);
	loser.addButton(r, QMessageBox::AcceptRole);
	// | QMessageBox::New);
	loser.setDefaultButton(r);
	connect(q, SIGNAL(clicked()), this, SLOT(quitGame()));
	// CONNECT START GAME
	//connect(r, SIGNAL(clicked()), this, SLOT(startGame()));
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
	//connect(r, SIGNAL(clicked()), this, SLOT(startGame()));
	connect(r, SIGNAL(clicked()), this, SLOT(resumeTime()));
	pause.exec();
	
}

void MainWindow::stopGame(){
	cout << "stop game" << endl;
}
void MainWindow::quitGame(){
	//quitting game
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
