// MyStatic.cpp : implementation file
//

#include "stdafx.h"
#include "afxpriv.h" // for WM_QUERY3DCONTROLS

#include "ControlExplorer.h"
#include "MyStatic.h"
#include "dlgcodes.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyStatic

CMyStatic::CMyStatic()
{
}

CMyStatic::~CMyStatic()
{
}


BEGIN_MESSAGE_MAP(CMyStatic, CStatic)
        //{{AFX_MSG_MAP(CMyStatic)
        ON_WM_GETDLGCODE()
        //}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyStatic message handlers

/****************************************************************************
*                         CMyStatic::OnGetDlgCode
* Result: UINT
*       DLG code flags
* Notes: 
*       This allows us to subclass a control and return specific flags for
*       the WM_GETDLGCODE.  These flags are kept in the low-order 16 bits.
*
*       In the high-order word, which we never return, we keep two flags:
*               DLGCX_VALID - the values in the flag word are valid
*                             If this flag is not set, we pass the message
*                             on to the superclass.
*               DLGCX_ACTIVE - the values in the flag word are active.
*                             If this flag is not set, we pass the message
*                             on to the superclass.
*       Note that both flags must be set to have this function override the
*       parent.
*
*       For now, we keep the value in the GWL_USERDATA word; in the future
*       we might attach it with AddProp and use GetProp
*
* 	This code duplicates similar code.  We could avoid this if we could
*	use multiple inheritance under MFC, but we can't use it, hence the
*	duplication.
****************************************************************************/

#define DLGCX_BOTH (DLGCX_VALID | DLGCX_ACTIVE)

UINT CMyStatic::OnGetDlgCode() 
{
 if((getDlgCode(m_hWnd) & DLGCX_BOTH) == DLGCX_BOTH)
    return getDlgCode(m_hWnd) & ~DLGCX_BOTH;
        
 return CStatic::OnGetDlgCode();
}
