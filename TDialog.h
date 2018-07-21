#if !defined(AFX_TDIALOG_H__82EA997A_829D_429F_B930_E23F52CFDB6B__INCLUDED_)
#define AFX_TDIALOG_H__82EA997A_829D_429F_B930_E23F52CFDB6B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TDialog.h : header file
//

#include "afxwin.h"
#define IDD_DIALOG1 2000
/////////////////////////////////////////////////////////////////////////////
// TDialog dialog

class TDialog : public CDialog
{
// Construction
public:
	TDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(TDialog)
	enum { IDD = IDD_DIALOG1 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(TDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(TDialog)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TDIALOG_H__82EA997A_829D_429F_B930_E23F52CFDB6B__INCLUDED_)
