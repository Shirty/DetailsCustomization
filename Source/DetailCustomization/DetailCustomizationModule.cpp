#include "DetailCustomization.h"
#include "Customization.h"

class FDetailCustomizationModule : public FDefaultGameModuleImpl
{
public:

	virtual void StartupModule() override
	{
		RegisterCustomizations();
	}

	virtual void ShutdownModule() override
	{
		UnregisterCustomizations();
	}

protected:

	void RegisterCustomizations()
	{
		FPropertyEditorModule& PropertyModule = FModuleManager::LoadModuleChecked<FPropertyEditorModule>("PropertyEditor");
		PropertyModule.RegisterCustomClassLayout(UExample::StaticClass()->GetFName(), FOnGetDetailCustomizationInstance::CreateStatic(&FExampleCustomization::MakeInstance));

	}

	void UnregisterCustomizations()
	{
		FPropertyEditorModule& PropertyModule = FModuleManager::LoadModuleChecked<FPropertyEditorModule>("PropertyEditor");
		PropertyModule.UnregisterCustomClassLayout(UExample::StaticClass()->GetFName());
	}
};


IMPLEMENT_PRIMARY_GAME_MODULE(FDetailCustomizationModule, DetailCustomization, "DetailCustomization")