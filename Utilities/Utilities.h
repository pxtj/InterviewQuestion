// ���� ifdef ���Ǵ���ʹ�� DLL �������򵥵�
// ��ı�׼�������� DLL �е������ļ��������������϶���� UTILITIES_EXPORTS
// ���ű���ġ���ʹ�ô� DLL ��
// �κ�������Ŀ�ϲ�Ӧ����˷��š�������Դ�ļ��а������ļ����κ�������Ŀ���Ὣ
// UTILITIES_API ������Ϊ�Ǵ� DLL ����ģ����� DLL ���ô˺궨���
// ������Ϊ�Ǳ������ġ�
//#define UTILITIES_EXPORTS 
#ifdef UTILITIES_EXPORTS
#define UTILITIES_API __declspec(dllexport)
#else
#define UTILITIES_API __declspec(dllimport)
#endif

// �����Ǵ� Utilities.dll ������
class UTILITIES_API CUtilities {
public:
	CUtilities(void);
	// TODO: �ڴ�������ķ�����
};

extern UTILITIES_API int nUtilities;

UTILITIES_API int fnUtilities(void);
