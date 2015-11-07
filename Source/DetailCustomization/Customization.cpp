#include "DetailCustomization.h"
#include "AssetData.h"
#include "PropertyHandle.h"
#include "Customization.h"

#include "DetailLayoutBuilder.h"
#include "DetailCategoryBuilder.h"
#include "IDetailGroup.h"
#include "DetailWidgetRow.h"
#include "IDetailPropertyRow.h"
#include "IDetailsView.h"

#define LOCTEXT_NAMESPACE "ExampleCustomization"

void FExampleCustomization::CustomizeDetails(IDetailLayoutBuilder& DetailBuilder)
{
	IDetailCategoryBuilder& CategoryBuilder = DetailBuilder.EditCategory(TEXT("Example"), LOCTEXT("NewCategoryName", "ExampleStructs"));

	// This is not an example of good slate code.
	DetailBuilder.GetObjectsBeingCustomized(Objects);
	for (auto Object : Objects)
	{
		UExample* Example = Cast<UExample>(Object.Get());
		if (Example)
		{
			for (auto& Elem : Example->ExampleMap)
			{
				IDetailGroup& Group = CategoryBuilder.AddGroup(Elem.Key, FText::FromString(Elem.Key.ToString()));
				FDetailWidgetRow& WidgetRow = Group.AddWidgetRow();
				WidgetRow
				[
					SNew(SHorizontalBox)
					+ SHorizontalBox::Slot()
					[
						SNew(SHorizontalBox)
						+ SHorizontalBox::Slot()
						[
							SNew(STextBlock)
							.Text(FText::FromString(FString("Var1")))
						]
						+ SHorizontalBox::Slot()
						[
							SNew(SEditableText)
							.Text(FText::FromString(FString::SanitizeFloat((Elem.Value.Var1))))
						]
					]
					+ SHorizontalBox::Slot()
					[
						SNew(SHorizontalBox)
						+ SHorizontalBox::Slot()
						[
							SNew(STextBlock)
							.Text(FText::FromString(FString("Var2")))
						]
						+ SHorizontalBox::Slot()
						[
							SNew(SEditableText)
							.Text(FText::FromString(FString::SanitizeFloat((Elem.Value.Var2))))
						]
					]
				];
			}
		}
	}
}

#undef LOCTEXT_NAMESPACE