// SnakeDoc.h : interface of the CSnakeDoc class
//


#pragma once
#include "asnake.h"


class CSnakeDoc : public CDocument
{
protected: // create from serialization only
	CSnakeDoc();
	DECLARE_DYNCREATE(CSnakeDoc)

// Attributes
public:

// Operations
public:

// Overrides
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// Implementation
public:
	virtual ~CSnakeDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	// Creates and destroy the thread to run the game
	void Suspend_Game(bool isRunning);
private:
	// Used to create the thread for the game
	CWinThread *m_pSnakeThread;
	// Our snake for the game
	aSnake * snakey;
public:
	// Draws our snake to the screen
	void DrawSnake(void);
	// Change the direction of snakey
	void changeDirection(int direction);
	// This is basically our game loop for entire game
	UINT GameLoop(LPVOID pParam);
};


