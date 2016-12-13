// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ue4_scripts/KGameModeBase.h"
#include "GameModeLogin.generated.h"


/**
 * 
 */
UCLASS()
class KBENGINE_UE4_DEMO_API AGameModeLogin : public AKGameModeBase
{
	GENERATED_UCLASS_BODY()
	
public:	
	/*
		��װ��½ʱ��Ҫ������KBE�¼�
	*/
	virtual void installEvents() override;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	/** Called once this actor has been deleted */
	virtual void Destroyed() override;

	UFUNCTION(BlueprintCallable, Category = "KBEngine")
	bool validEmail(FString strEmail);

	/* KBE�¼�
	*/
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "KBEngine")
	void onCreateAccountResult(const UKBEventData* pEventData);

	/* KBE�¼�
	*/
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "KBEngine")
	void onLoginFailed(const UKBEventData* pEventData);

	/* KBE�¼�
	*/
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "KBEngine")
	void onVersionNotMatch(const UKBEventData* pEventData);

	/* KBE�¼�
	*/
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "KBEngine")
	void onScriptVersionNotMatch(const UKBEventData* pEventData);

	/* KBE�¼�
	*/
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "KBEngine")
	void onLoginBaseappFailed(const UKBEventData* pEventData);

	/* KBE�¼�
	*/
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "KBEngine")
	void onLoginSuccessfully(const UKBEventData* pEventData);

	/* KBE�¼�
	*/
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "KBEngine")
	void onLoginBaseapp(const UKBEventData* pEventData);

	/* KBE�¼�
	*/
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "KBEngine")
	void Loginapp_importClientMessages(const UKBEventData* pEventData);

	/* KBE�¼�
	*/
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "KBEngine")
	void Baseapp_importClientMessages(const UKBEventData* pEventData);

	/* KBE�¼�
	*/
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "KBEngine")
	void Baseapp_importClientEntityDef(const UKBEventData* pEventData);
};
