// SnakeDoc.cpp : implementation of the CSnakeDoc class
//

#include "stdafx.h"
#include "Snake.h"

#include "SnakeDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSnakeDoc

IMPLEMENT_DYNCREATE(CSnakeDoc, CDocument)

BEGIN_MESSAGE_MAP(CSnakeDoc, CDocument)
END_MESSAGE_MAP()


// CSnakeDoc construction/destruction

CSnakeDoc::CSnakeDoc()
: m_pBlobThread(NULL)
{
	// TODO: add one-time construction code here

}

CSnakeDoc::~CSnakeDoc()
{
}

BOOL CSnakeDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)
    Suspense_Game(true);
	return TRUE;
}




// CSnakeDoc serialization

void CSnakeDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}


// CSnakeDoc diagnostics

#ifdef _DEBUG
void CSnakeDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CSnakeDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// Creates and destroy the thread to run the game

void CSnakeDoc::Suspend_Game(bool isRunning)
{
	
	//You only need one function to turn the thread off or on
	if(!isRunning)
	{
		if(m_pBlobThread)
		{
			HANDLE hThread = m_pSnakeThread->m_hThread;
			::WaitForSingleObject(hThread, INFINITE);
		}
	}
	else
	{
		//ThreadFunc is the function that will be called m_pBlob the object it will work on
		//I think AfxBeginThread is a callback function?  Does this make C++ a functional programming language?
		m_pSnakeThread = AfxBeginThread(GameLoop,(LPVOID)snakey);
	}
}

// Draws our snake to the screen
void CSnakeDoc::DrawSnake(void)
{
	snakey->draw();
}

// Change the direction of snakey
void CSnakeDoc::changeDirection(int direction)
{
	if(direction == 1){
		snakey->moveLeft();
	}else if(direction == 2){
		snakey_>moveRight();
	}else if(direction == 3){
		snakey->moveUp();
	}else if(direction == 4){
		snakey->moveDown();
	}
}

// This is basically our game loop for entire game
UINT CSnakeDoc::GameLoop(LPVOID pParam)
{
	// I know I am using a thread so don't have to find out the type of pParam just cast it to a blob pointer
	aSnake * ourSnake = (aSnake *) pParam;
	CBitmap grapeImg;
	CBitmap appleImg;
	CBitmap poisonBerry;

	offSetx = 0;
	offSety=0;
	CPoint * fPos = new CPoint(0,0);
	srand(time(NULL));
     fPos.x = rand()%screenWidth + offSetx;
	 fPos.y = rand()%screenHeight + offSety;
     int type = rand()%3 + 1;

	Food ourFood = new Food(fPos,,type);
	while(ourSnake->isAlive()){
		clear();
		ourSnake->move();
		bool ans = ourSnake->collision(ourFood);
		if(ans){
			ourSnake->setScore(ourSnake->getScore()+ ourFood->getValue()); 
			ourSnake->displayScore(pDC);
			if(ourFood->getValue() < 0){
				ourSnake->Shrink();
			}else{
				ourSnake->Grow();
			}
			srand(time(NULL));
            fPos.x = rand()%screenWidth + offSetx;
	        fPos.y = rand()%screenHeight + offSety;
			type = rand()%3 + 1;
			ourFood = new Food(fpos,,type);
		}
        ourFood->draw();
		ourSnake->draw();

		//Note clock_t is a class define in ctime
		//interval will determine how often you update the blob 
		//In a more complex came we need to keep this synchronised with the main thread
		int interval = 128;
		for (clock_t t = clock() + CLOCKS_PER_SEC/interval;  clock() <t;);
	}
	AfxEndThread(0,true);
	return 0;
}
