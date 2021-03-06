#pragma once

#include "tp_stub.h"
#include <string>
// CExtractView 对话框

#pragma comment(lib, "Version.lib")

class CExtractView : public CDialogEx
{
	DECLARE_DYNAMIC(CExtractView)

public:
	CExtractView(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CExtractView();

	void Init(PVOID HostAlloc, PVOID CallTVPCreateStreamCall, ULONG_PTR IStreamAdapterVtable, std::wstring Version);


// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_KRKRZ_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedStopButton();
	afx_msg void OnBnClickedExitButton();


	void SetDumperStatus(BOOL IsInUse = TRUE);

private:
	void BaseInit();

public:
	CRITICAL_SECTION          m_DumperCS;

	using CreateStreamFunc = tTJSBinaryStream* (FASTCALL *)(const ttstr &, tjs_uint32);
	CreateStreamFunc          CreateStreamStub;
	PVOID                     m_HostAlloc;
	PVOID                     m_CallTVPCreateStreamCall;
	ULONG_PTR                 m_IStreamAdapterVtable;
	BOOL                      m_InDumpingStatus;
	std::wstring              m_Version;

	afx_msg void OnBnClickedBeginButton();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	virtual BOOL OnInitDialog();
};
