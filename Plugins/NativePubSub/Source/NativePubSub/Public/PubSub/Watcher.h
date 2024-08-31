#pragma once
#include "Publisher.h"
#include "Receiver.h"

class FWatcher final : INode
{
private:
	const FPublisher Publisher;	
public:
	FWatcher()
	:Publisher(FPublisher()){}
	
	virtual const int Id() const override;
	void Watch(const FReceiveDelegate& ReceiveDelegate);
	void Unwatch();

	void Publish(TSharedPtr<const FMessage> Message) const;
};
