#ifndef CLIENT_MESSAGE_HANDLER_C_H
#define CLIENT_MESSAGE_HANDLER_C_H


#include "..\Infrastructure\IMessageHandler.h"
#include "UserInterface.h"

//#include <conio.h>
#include <vcclr.h>

//Declare UserInterface /*Syntax "ref class Client::UserInter;" is error */
 namespace Client
 {
 	ref class UserInterface;
 }

class MessageHandler:public Ider::IMessageHandler
{
public:
	MessageHandler(){}
	MessageHandler(Client::UserInterface^ form){_form = form;}
	virtual void ReceiveMessage(conStrRef message );
	virtual Ider::Message MessageForSending(Ider::MsgType::Value type);

	//

	strVal Convert(System::String^ s);
	System::String^ Convert(conStrRef s);

	//void SetForm(Client::UserInterface^ form){_form = form;}

protected:
	//
	virtual void FileProcess();
	virtual void LoginProcess();
	virtual void CheckinProcess();
	virtual void DependencyProcess();
	virtual void WarningProcess();

	//
	virtual Ider::Message FileMessage();
	virtual Ider::Message CheckinMessage();
	virtual Ider::Message LoginMessage();
	virtual Ider::Message DependencyMessage();
	//virtual Ider::Message WarningMessage(std::string warning);
	strVal GetName(Ider::MsgType::Value type);
	void ShowWarning(strVal warning);

private:
	Ider::Message _msg;
	//msclr::auto_gcroot<Client::UserInterface^>_form;
	gcroot<Client::UserInterface^> _form;
};


#endif