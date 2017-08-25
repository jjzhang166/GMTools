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
	void updateUIMsg(char* msg);		// 更新消息列表UI
	void updateUICmd(QString pCmd);		// 更新
private:
	static UIEventManager* sUIManager;
	
	GMTools* _gm;
};

