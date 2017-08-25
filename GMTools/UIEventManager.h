#pragma once
#include <QString>
class GMTools;
class UIEventManager
{
public:
	UIEventManager(void);
	~UIEventManager(void);

	static inline UIEventManager* getInstence()
	{
		if (!sUIManager)
		{
			sUIManager = new UIEventManager();
		}
		return sUIManager;
	}
	
	void saveGmObject(GMTools* gm);
	GMTools* getGmObject();
	void updateUIMsg(char* msg);		// ������Ϣ�б�UI
	void updateUICmd(QString pCmd);		// ����
private:
	static UIEventManager* sUIManager;
	
	GMTools* _gm;
};

