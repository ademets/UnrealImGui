// Distributed under the MIT License (MIT) (see accompanying LICENSE file)

#include "ImGUIBPLibrary.h"
#include "ImGUIBlueprintLibrary.h"
#include "Converter.h"
#include "ImGuiCommon.h"

//Exemples on
//	ImGui::ShowDemoWindow()

UImGUIBPLibrary::UImGUIBPLibrary(const FObjectInitializer& ObjectInitializer): Super(ObjectInitializer)
{
	
}

void UImGUIBPLibrary::ShowDemoWindow()
{
#if WITH_IMGUI
	ImGui::ShowDemoWindow();
#endif
}

void UImGUIBPLibrary::ShowMetricsWindow()
{
#if WITH_IMGUI
	ImGui::ShowMetricsWindow();
#endif
}

void UImGUIBPLibrary::ShowAboutWindow()
{
#if WITH_IMGUI
	ImGui::ShowAboutWindow();
#endif
}

void UImGUIBPLibrary::ShowStyleEditor()
{
#if WITH_IMGUI
	ImGui::ShowStyleEditor();
#endif
}

void UImGUIBPLibrary::ShowStyleSelector(FString Label)
{
#if WITH_IMGUI
	ImGui::ShowStyleSelector(TCHAR_TO_ANSI(*Label));
#endif
}

void UImGUIBPLibrary::ShowFontSelector(FString Label)
{
#if WITH_IMGUI
	ImGui::ShowFontSelector(TCHAR_TO_ANSI(*Label));
#endif
}

void UImGUIBPLibrary::ShowUserGuide()
{
#if WITH_IMGUI
	ImGui::ShowUserGuide();
#endif
}

FString UImGUIBPLibrary::GetVersion()
{
	FString Version;
#if WITH_IMGUI
	Version = ImGui::GetVersion();
#endif
	return Version;
}

void UImGUIBPLibrary::SetFont(FString Path, int Size)
{
	ImGuiIO& io = ImGui::GetIO();
	ImFontConfig FontConfig = {};
	FPlatformString::Strcpy(FontConfig.Name, sizeof(FontConfig.Name), TCHAR_TO_ANSI(*Path));
	io.Fonts->AddFontFromFileTTF(TCHAR_TO_ANSI(*Path), Size, &FontConfig);
	unsigned char* Pixels;
	int Width, Height, Bpp;
	io.Fonts->GetTexDataAsRGBA32(&Pixels, &Width, &Height, &Bpp);

}

void UImGUIBPLibrary::SetThemeCustom()
{
	ImVec4* colors = ImGui::GetStyle().Colors;
	colors[ImGuiCol_WindowBg] = ImVec4(0.13f, 0.12f, 0.15f, 0.94f);
	colors[ImGuiCol_FrameBg] = ImVec4(0.44f, 0.44f, 0.44f, 0.60f);
	colors[ImGuiCol_MenuBarBg] = ImVec4(0.71f, 0.18f, 0.18f, 1.00f);
	colors[ImGuiCol_ScrollbarBg] = ImVec4(0.75f, 0.08f, 0.08f, 0.53f);
	colors[ImGuiCol_Button] = ImVec4(0.79f, 0.98f, 0.26f, 0.40f);
	colors[ImGuiCol_ButtonHovered] = ImVec4(0.98f, 0.26f, 0.57f, 1.00f);
	colors[ImGuiCol_ButtonActive] = ImVec4(0.18f, 0.74f, 0.26f, 1.00f);
	colors[ImGuiCol_Header] = ImVec4(0.26f, 0.59f, 0.92f, 0.31f);
	colors[ImGuiCol_Tab] = ImVec4(0.58f, 0.18f, 0.18f, 0.86f);
	colors[ImGuiCol_TabHovered] = ImVec4(0.79f, 0.94f, 0.09f, 0.80f);
	colors[ImGuiCol_TabActive] = ImVec4(0.66f, 0.68f, 0.20f, 1.00f);
}
void UImGUIBPLibrary::SetThemeRed()
{
	ImVec4* colors = ImGui::GetStyle().Colors;
	colors[ImGuiCol_Text] = ImVec4(0.75f, 0.75f, 0.75f, 1.00f);
	colors[ImGuiCol_TextDisabled] = ImVec4(0.35f, 0.35f, 0.35f, 1.00f);
	colors[ImGuiCol_WindowBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.94f);
	colors[ImGuiCol_ChildBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
	colors[ImGuiCol_PopupBg] = ImVec4(0.08f, 0.08f, 0.08f, 0.94f);
	colors[ImGuiCol_Border] = ImVec4(0.00f, 0.00f, 0.00f, 0.50f);
	colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
	colors[ImGuiCol_FrameBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.54f);
	colors[ImGuiCol_FrameBgHovered] = ImVec4(0.37f, 0.14f, 0.14f, 0.67f);
	colors[ImGuiCol_FrameBgActive] = ImVec4(0.39f, 0.20f, 0.20f, 0.67f);
	colors[ImGuiCol_TitleBg] = ImVec4(0.04f, 0.04f, 0.04f, 1.00f);
	colors[ImGuiCol_TitleBgActive] = ImVec4(0.48f, 0.16f, 0.16f, 1.00f);
	colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.48f, 0.16f, 0.16f, 1.00f);
	colors[ImGuiCol_MenuBarBg] = ImVec4(0.14f, 0.14f, 0.14f, 1.00f);
	colors[ImGuiCol_ScrollbarBg] = ImVec4(0.02f, 0.02f, 0.02f, 0.53f);
	colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.31f, 0.31f, 0.31f, 1.00f);
	colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.41f, 0.41f, 0.41f, 1.00f);
	colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.51f, 0.51f, 0.51f, 1.00f);
	colors[ImGuiCol_CheckMark] = ImVec4(0.56f, 0.10f, 0.10f, 1.00f);
	colors[ImGuiCol_SliderGrab] = ImVec4(1.00f, 0.19f, 0.19f, 0.40f);
}
void UImGUIBPLibrary::SetThemePurple()
{
	ImVec4* colors = ImGui::GetStyle().Colors;

	colors[ImGuiCol_Text] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
	colors[ImGuiCol_TextDisabled] = ImVec4(0.50f, 0.50f, 0.50f, 1.00f);
	colors[ImGuiCol_WindowBg] = ImVec4(0.27f, 0.27f, 0.28f, 1.00f);
	colors[ImGuiCol_ChildBg] = ImVec4(0.27f, 0.27f, 0.28f, 1.00f);
	colors[ImGuiCol_PopupBg] = ImVec4(0.08f, 0.08f, 0.08f, 1.00f);
	colors[ImGuiCol_Border] = ImVec4(0.27f, 0.27f, 0.28f, 1.00f);
	colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
	colors[ImGuiCol_FrameBg] = ImVec4(0.18f, 0.18f, 0.19f, 1.00f);
	colors[ImGuiCol_FrameBgHovered] = ImVec4(0.61f, 0.35f, 0.71f, 1.00f);
	colors[ImGuiCol_FrameBgActive] = ImVec4(0.61f, 0.35f, 0.71f, 1.00f);
	colors[ImGuiCol_TitleBg] = ImVec4(0.27f, 0.27f, 0.28f, 1.00f);
	colors[ImGuiCol_TitleBgActive] = ImVec4(0.27f, 0.27f, 0.28f, 1.00f);
	colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.27f, 0.27f, 0.28f, 1.00f);
	colors[ImGuiCol_MenuBarBg] = ImVec4(0.27f, 0.27f, 0.28f, 1.00f);
	colors[ImGuiCol_ScrollbarBg] = ImVec4(0.27f, 0.27f, 0.28f, 1.00f);
	colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.13f, 0.13f, 0.13f, 1.00f);
	colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.36f, 0.38f, 0.39f, 1.00f);
	colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.36f, 0.38f, 0.39f, 1.00f);
	colors[ImGuiCol_CheckMark] = ImVec4(0.56f, 0.27f, 0.68f, 1.00f);
	colors[ImGuiCol_SliderGrab] = ImVec4(0.56f, 0.27f, 0.68f, 1.00f);
	colors[ImGuiCol_SliderGrabActive] = ImVec4(0.56f, 0.27f, 0.68f, 1.00f);
	colors[ImGuiCol_Button] = ImVec4(0.36f, 0.38f, 0.39f, 1.00f);
	colors[ImGuiCol_ButtonHovered] = ImVec4(0.61f, 0.35f, 0.71f, 1.00f);
	colors[ImGuiCol_ButtonActive] = ImVec4(0.56f, 0.27f, 0.68f, 1.00f);
	colors[ImGuiCol_Header] = ImVec4(0.27f, 0.27f, 0.28f, 1.00f);
	colors[ImGuiCol_HeaderHovered] = ImVec4(0.27f, 0.27f, 0.28f, 1.00f);
	colors[ImGuiCol_HeaderActive] = ImVec4(0.27f, 0.27f, 0.28f, 1.00f);
	colors[ImGuiCol_Separator] = ImVec4(0.43f, 0.43f, 0.50f, 0.50f);
	colors[ImGuiCol_SeparatorHovered] = ImVec4(0.61f, 0.35f, 0.71f, 1.00f);
	colors[ImGuiCol_SeparatorActive] = ImVec4(0.56f, 0.27f, 0.68f, 1.00f);
	colors[ImGuiCol_ResizeGrip] = ImVec4(0.36f, 0.38f, 0.39f, 1.00f);
	colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.61f, 0.35f, 0.71f, 1.00f);
	colors[ImGuiCol_ResizeGripActive] = ImVec4(0.56f, 0.27f, 0.68f, 1.00f);
	colors[ImGuiCol_PlotLines] = ImVec4(0.61f, 0.61f, 0.61f, 1.00f);
	colors[ImGuiCol_PlotLinesHovered] = ImVec4(0.60f, 0.36f, 0.76f, 0.40f);
	colors[ImGuiCol_PlotHistogram] = ImVec4(0.61f, 0.35f, 0.71f, 1.00f);
	colors[ImGuiCol_PlotHistogramHovered] = ImVec4(0.56f, 0.27f, 0.68f, 1.00f);
	colors[ImGuiCol_TextSelectedBg] = ImVec4(0.26f, 0.59f, 0.98f, 0.35f);
	//colors[ImGuiCol_ModalWindowDarkening] = ImVec4(0.80f, 0.80f, 0.80f, 0.35f);
	colors[ImGuiCol_DragDropTarget] = ImVec4(1.00f, 1.00f, 0.00f, 0.90f);
	colors[ImGuiCol_NavHighlight] = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
	colors[ImGuiCol_NavWindowingHighlight] = ImVec4(1.00f, 1.00f, 1.00f, 0.70f);

	ImGuiStyle& style = ImGui::GetStyle();

	style.FrameRounding = 3;
}

bool UImGUIBPLibrary::Begin(FString Name,bool bOpen,int Flags)
{
	bool ReturnValue = false;
#if WITH_IMGUI
	ReturnValue = ImGui::Begin(TCHAR_TO_ANSI(*Name),&bOpen,Flags);
	
#endif
	return ReturnValue;
}

void UImGUIBPLibrary::Begin_Event(FString Name,bool bOpen,int Flags, const FOnVoidDelegate& OnEnabled)
{
	if (Begin(Name,bOpen,Flags) && OnEnabled.IsBound())
	{
		OnEnabled.Execute();
	}
	End();
}

void UImGUIBPLibrary::End()
{
#if WITH_IMGUI
	ImGui::End();
#endif
}

bool UImGUIBPLibrary::BeginChild(FString ID, FVector2D Size, bool bBorder, int Flags)
{
	bool ReturnValue = false;
#if WITH_IMGUI
	ReturnValue = ImGui::BeginChild(TCHAR_TO_ANSI(*ID),Converter::FVector2DToImVec2(Size),bBorder,Flags);
#endif
	return ReturnValue;
}

void UImGUIBPLibrary::BeginChild_Event(FString ID, FVector2D Size, bool bBorder, int Flags,const FOnVoidDelegate& OnEnabled)
{
	if (BeginChild(ID,Size,bBorder,Flags) && OnEnabled.IsBound())
	{
		OnEnabled.Execute();
	}
}

bool UImGUIBPLibrary::BeginChild_IntID(int ID, FVector2D Size, bool bBorder, int Flags)
{
	bool ReturnValue = false;
#if WITH_IMGUI
	ReturnValue = ImGui::BeginChild(ID,Converter::FVector2DToImVec2(Size),bBorder,Flags);
#endif
	return ReturnValue;
}

void UImGUIBPLibrary::BeginChild_IntID_Event(int ID, FVector2D Size, bool bBorder, int Flags,const FOnVoidDelegate& OnEnabled)
{
	if (BeginChild_IntID(ID,Size,bBorder,Flags) && OnEnabled.IsBound())
	{
		OnEnabled.Execute();
	}
	EndChild();
}

void UImGUIBPLibrary::EndChild()
{
#if WITH_IMGUI
	ImGui::EndChild();
#endif
}

void UImGUIBPLibrary::Text(FString Text)
{
#if WITH_IMGUI
	ImGui::Text("%s", TCHAR_TO_ANSI(*Text));
#endif
}

bool UImGUIBPLibrary::InputFloat(FString Label,float& Value,float Step,float StepFast,int FractionalDigits,int Flags)
{
	bool ReturnValue = false;
#if WITH_IMGUI
	ReturnValue = ImGui::InputFloat(TCHAR_TO_ANSI(*Label),&Value,Step,StepFast,Converter::FloatFormat(FractionalDigits),Flags);
#endif
	return ReturnValue;
}

void UImGUIBPLibrary::InputFloat_Event(FString Label, float& Value, float Step, float StepFast,int FractionalDigits, int Flags, const FOnFloatDelegate& OnValueChanged)
{
	if (InputFloat(Label,Value,Step,StepFast,FractionalDigits,Flags) && OnValueChanged.IsBound())
	{
		OnValueChanged.Execute(Value);
	}
}



