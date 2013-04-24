#include "mainwindow.h"
using namespace std;

MainWindow::MainWindow()
{		level=1;
		score=0;
		count=0;
		lives = 5;
		game_in_play =false;
		scene = new QGraphicsScene(0, 0, WINDOW_MAX_X*2+100, WINDOW_MAX_Y*2+100);
		//creating a new graphics scene
    view = new QGraphicsView();// scene );
    view->setFixedSize( WINDOW_MAX_X*2, WINDOW_MAX_Y*2 );
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setSceneRect(WINDOW_MAX_X*2, WINDOW_MAX_Y*2 );
    mainW = new QMainWindow;
    mainW->setCentralWidget(view);
    mainW->setWindowTitle("Under The Sea");
    QPixmap back("water.jpg");
    //graphicsView->setAlignment( Qt::AlignLeft | Qt::AlignTop
    //setSceneRect( 0, 0, width, height ); 
    //QPainter *p;
    //p->drawPixMap(QRect(0,0,WINDOW_MAX_X*2, WINDOW_MAX_Y*2, back);
    scene->setBackgroundBrush(back.scaled(WINDOW_MAX_X*2+100, WINDOW_MAX_Y*2+100, Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
    view->setScene(scene);
    createStartScreen();
    //mainW->setDockNestingEnabled(true);
    mainW->addDockWidget(Qt::TopDockWidgetArea, titleArea);
    //menu->move(100, 200);
    createMenuArea();
    mainW->addDockWidget(Qt::BottomDockWidgetArea, menuArea);
    createScoreArea();
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
		scene->clear();
		menuArea = new QDockWidget(this);
		QWidget *holder = new QWidget;	
    start = new QPushButton("&Start");
    start->setFixedHeight(40);
    pause = new QPushButton("&Pause");
    pause->setFixedHeight(40);
    stop = new QPushButton("End Game");
    stop->setFixedHeight(40);
 		quit = new QPushButton("&Quit");
 		quit->setFixedHeight(40);
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
    layout->addWidget(lives_label, 0, 3, 0, 4, Qt::AlignLeft);
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
    
    layout->addWidget(start, 1, 0, 1, 1, Qt::AlignCenter);
    layout->addWidget(pause, 1, 2, 1, 3, Qt::AlignCenter);
    layout->addWidget(stop, 1, 4, 1, 5, Qt::AlignCenter);
    layout->addWidget(quit, 1, 6, 1, 7, Qt::AlignCenter); 
  	holder->setLayout(layout);
  	menuArea->setWidget(holder);
  	menuArea->setFeatures(QDockWidget::NoDockWidgetFeatures);
    menuArea->show();
}

void MainWindow::createScoreArea(){
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
	game_in_play = true;
	cout << "start game" << endl;
	mermaid = new Mermaid;
	scene->addItem(mermaid);
	qreal x = mermaid->pos().x();
	qreal y = mermaid->pos().y();
	mermaid->setFocus();
	scene->setFocusItem(mermaid);//mainW->setFocus(mermaid);
	//view->setFocusPolicy(Qt::NoFocus);
	
	/*shark_pic = new Pixmap("sharky.png");
	bubble_pic = new Pixmap("power.png");
	fire_pic = new Pixmap("fire.png");
	boat_pic = new Pixmap("hull.png");*/
	// NEED TO WRITE MOUSE PRESS EVENTS IN SCREEN 
	timer = new QTimer(this);
	timer->setInterval(5);
	connect(timer, SIGNAL(timeout()), this, SLOT(handleTimer()));
	timer->start();
		

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
	bool shark_here = 0;
//check for collisions
//collides withssssss
		//boat
		//shark
		//fire
		//bubble
	int createS =rand()%4;
	switch(createS){
		case 0:
			//Shark *s1 = new Shark(shark_pic, rand()%500, rand()%900, 50, mermaid->y_);
			//sharks.push_back(s1);
			//on_screen.push_back(s1);
			break;
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
		break;
	}
	/*QLinkedList<GameItem*>::iterator it;
	for(it=on_screen.begin(); it!=on_screen.end(); ++it){
			*it->move();
	}
	QVector<Shark*>::iterator it2;
	for(it2=sharks.begin(); it!=sharks.end(); ++it){
		it2->setGoals(50, mermaid->y_);
	}*/
	//have everything move do move functions
	if(score==2000){
	//emit level up?
		//set velocities
		//every certain number on counter appears sharks and
			//more sparse appear boats
			//bubbles every in a blue moon
	}
	if(score==5000){
		//reset velocities
				//tiki man appears
				QPixmap *tiki_pic=new QPixmap("tiki.png");
				tiki = new Tiki(tiki_pic, 550, 350);
				scene->addItem(tiki);
			//velocity is incremented for boats and sharks
			//bubbles more often
	}
	if(score==8000){
		//velocity increases on boats, sharks, and bullets
			//bubbles less often
		
	
	}
	if(lives==0){
		emit death();
	}
	if(count%400==0){
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

void MainWindow::scoreFunct(int points){
	score+=points;
	score_label->setNum(score);
	//NEED TO UPDATE score print out on scene
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
	if(game_in_play=true){
		mermaid->keyPressEvent(k);
	}
}

void MainWindow::mousePressEvent(QMouseEvent *e){
	return;
}

void MainWindow::resumeTime(){
	timer->start();
}
