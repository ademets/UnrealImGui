// Distributed under the MIT License (MIT) (see accompanying LICENSE file)

#pragma once

#include <UObject/WeakObjectPtr.h>
#include <Widgets/DeclarativeSyntaxSupport.h>
#include <Widgets/SCompoundWidget.h>


class FImGuiModuleManager;
class UGameViewportClient;
struct FImGuiDPIScaleInfo;
class UWidgetComponent;
class USceneComponent;
// if class==UWidgetComponent, then use it as Panel, otherwise intanciate new UWidgetComponent using windowname
// if true, and Parent!=null, then SpawnPosition is relativ
// if true, disable all Viewport based code, and use WidgetComponent stuff instead
// Layout preset for ImGui Widget.
class SImGuiLayout : public SCompoundWidget
{
	typedef SCompoundWidget Super;

public:

	SLATE_BEGIN_ARGS(SImGuiLayout)
	{}
	SLATE_ARGUMENT(FImGuiModuleManager*, ModuleManager)
	SLATE_ARGUMENT(UGameViewportClient*, GameViewport)
	SLATE_ARGUMENT(int32, ContextIndex)
	SLATE_ARGUMENT(FVector, SpawnPosition)
	SLATE_ARGUMENT(USceneComponent*, Parent)
	SLATE_ARGUMENT(bool, IsSpawnPositionRelative)
	SLATE_ARGUMENT(bool, SpawnAsWidgetComponent)
	SLATE_ARGUMENT(UWidgetComponent*, WidgetComponent)
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs);

	~SImGuiLayout();

	const TWeakObjectPtr<UGameViewportClient>& GetGameViewport() const { return GameViewport; }

private:

	float GetDPIScale() const { return DPIScale; }
	void SetDPIScale(const FImGuiDPIScaleInfo& ScaleInfo);

	FImGuiModuleManager* ModuleManager = nullptr;
	TWeakObjectPtr<UGameViewportClient> GameViewport;

	float DPIScale = 1.f;
};
