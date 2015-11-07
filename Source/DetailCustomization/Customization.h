#include "SharedPointer.h"
#include "IDetailCustomization.h"

class FExampleCustomization : public IDetailCustomization
{
public:
	virtual void CustomizeDetails(IDetailLayoutBuilder& DetailBuilder) override;

	static TSharedRef<IDetailCustomization> MakeInstance()
	{
		return MakeShareable(new FExampleCustomization());
	}

	TArray<TWeakObjectPtr<UObject>> Objects;
};