
// FlyGLView.cpp : implementation of the CFlyGLView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "FlyGL.h"
#endif

#include "FlyGLDoc.h"
#include "FlyGLView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CFlyGLView

IMPLEMENT_DYNCREATE(CFlyGLView, CView)

BEGIN_MESSAGE_MAP(CFlyGLView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CFlyGLView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CFlyGLView construction/destruction

CFlyGLView::CFlyGLView()
{
	// TODO: add construction code here

}

CFlyGLView::~CFlyGLView()
{
}

BOOL CFlyGLView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CFlyGLView drawing

void CFlyGLView::OnDraw(CDC* /*pDC*/)
{
	CFlyGLDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CFlyGLView printing


void CFlyGLView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CFlyGLView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CFlyGLView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CFlyGLView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CFlyGLView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CFlyGLView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CFlyGLView diagnostics

#ifdef _DEBUG
void CFlyGLView::AssertValid() const
{
	CView::AssertValid();
}

void CFlyGLView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CFlyGLDoc* CFlyGLView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CFlyGLDoc)));
	return (CFlyGLDoc*)m_pDocument;
}
#endif //_DEBUG


// CFlyGLView message handlers
