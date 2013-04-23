#include "mainwindow.h"
using namespace std;

MainWindow::MainWindow()
{		level=1;
		score=0;
		count=0;
		scene = new QGraphicsScene(0, 0, WINDOW_MAX_X*2, WINDOW_MAX_Y*2);
		//creating a new graphics scene
    view = new QGraphicsView();// scene );
    view->setFixedSize( WINDOW_MAX_X*2+5, WINDOW_MAX_Y*2+5 );
    mainW = new QMainWindow;
    mainW->setCentralWidget(view);
    mainW->setWindowTitle("Under The Sea");
    QPixmap back("water.jpg");
    //graphicsView->setAlignment( Qt::AlignLeft | Qt::AlignTop
    //setSceneRect( 0, 0, width, height ); 
    //QPainter *p;
    //p->drawPixMap(QRect(0,0,WINDOW_MAX_X*2, WINDOW_MAX_Y*2, back);
    scene->setBackgroundBrush(back.scaled(WINDOW_MAX_X*2, WINDOW_MAX_Y*2, Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
    view->setScene(scene);
    createStartScreen();
    scene->addWidget(menu);
    menue->move(100, 200);
    createMenuArea();
    mainW->addDockWidget(Qt::BottomDockWidgetArea, menuArea);
    createScoreArea();
    mainW->addDockWidget(Qt::TopDockWidgetArea, scoreArea);
    
    connect(start, SIGNAL(clicked()), this, SLOT(startGame()));
    connect(pause, SIGNAL(clicked()), this, SLOT(pauseGame()));
    connect(stop, SIGNAL(clicked()), this, SLOT(stopGame()));
    connect(quit, SIGNAL(clicked()), this, SLOT(quitGame()));
}

MainWindow::~MainWindow()
{
	delete scene;
	delete view;
}

void MainWindow::createStartScreen(){
	menu = new QWidget;
	player_name = new QLineEdit;  //// make start menu
	QLabel* title = new QLabel(this);
	QLabel* subtitle = new QLabel(this);
	QLabel* instructions = new QLabel(this);
	QPixmap picture("UnderTheSea.png");
	title->setPixmap(picture);
	//title->setMask(picture.mask());
	title->setAlignment(Qt::AlignTop | Qt::AlignCenter);
	subtitle->setText("An intereactive Mermaid game!");
	subtitle->setAlignment(Qt::AlignCenter | Qt::AlignCenter);
	instructions->setText("Input player name and \npress Start to play.\nGood Luck!");
	QLabel * playerName = new QLabel("Name: ", this);
	playerName->setBuddy(player_name);
	instructions->setAlignment(Qt::AlignCenter | Qt::AlignCenter);
	QVBoxLayout *layout = new QVBoxLayout;
	layout->addWidget(title);
	layout->addWidget(subtitle);
	layout->addWidget(instructions);
	menu->setLayout(layout);
	menu->show();

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
    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(start);
    layout->addWidget(pause);
    layout->addWidget(stop);
    layout->addWidget(quit); 
  	holder->setLayout(layout);
  	menuArea->setWidget(holder);
  	menuArea->setFeatures(QDockWidget::NoDockWidgetFeatures);
    menuArea->show();
}

void MainWindow::createScoreArea(){
// LEFT OFF HERE MAKING THE WORDS THAT YOU NEED!!!
		scoreArea = new QDockWidget(this);
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
    scoreArea->show();
}
void MainWindow::show(){
	mainW->show();
	//showing all this beautiful code to the user
}

void MainWindow::startGame(){
	cout << "start game" << endl;
	mermaid = new Mermaid;
	scene->addItem(mermaid);
	qreal x = mermaid->pos().x();
	qreal y = mermaid->pos().y();
	
	scene->setFocusItem(mermaid);//mainW->setFocus(mermaid);
	timer = new QTimer(this);
	timer->setInterval(5);
	connect(timer, SIGNAL(timeout()), this, SLOT(counter()));
	//if(score==)
	
	while(level==1){
		if(count%100==0){
		Shark *m1 = new Shark;
		scene->addItem(m1);
		//on_screen.push_back(m1);
		}
	
	}
	while(level==2){
	
	}
	while(level==3){
	
	
	}
}

void MainWindow::counter(){
	scoreFunct(1);
	count++;
}
void MainWindow::loseLife(){

}
void MainWindow::gainLife(){
}

void MainWindow::scoreFunct(int points){
	score+=points;
	//NEED TO UPDATE score print out on scene
}
void MainWindow::pauseGame(){
// NEEDS TO BE FIXED
	QMessageBox pause;
	pause.setText("Game is paused");
	pause.setInformativeText("What would you like to do?");
	pause.setStandardButtons(QMessageBox::Ok | QMessageBox::Abort);// | QMessageBox::New);
	pause.setDefaultButton(QMessageBox::Ok);
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
