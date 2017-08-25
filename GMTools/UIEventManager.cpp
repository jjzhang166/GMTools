#include "UIEventManager.h"
#include <string>
#include "gmtools.h"

UIEventManager* UIEventManager::sUIManager = NULL;

UIEventManager::UIEventManager(void)
{
}


UIEventManager::~UIEventManager(void)
{
}
void UIEventManager::saveGmObject(GMTools* gm)
{
	this->_gm = gm;
}

GMTools* UIEventManager::getGmObject()
{
	return this->_gm;
}

void UIEventManager::updateUIMsg(char* msg)
{
	this->_gm->updateMsg(msg);
}

void UIEventManager::updateUICmd(QString pCmd)
{
	this->_gm->updateCmd(pCmd);
}