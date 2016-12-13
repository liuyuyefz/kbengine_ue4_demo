// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "ue4_scripts/KGameModeBase.h"
#include "GameModeSelectAvatar.generated.h"

/**
 * 
 */
UCLASS()
class KBENGINE_UE4_DEMO_API AGameModeSelectAvatar : public AKGameModeBase
{
	GENERATED_UCLASS_BODY()

public:
	/*
		��װ��½ʱ��Ҫ������KBE�¼�
	*/
	virtual void installEvents() override;

	/* KBE�¼�
	*/
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "KBEngine")
	void onReqAvatarList(const UKBEventData* pEventData);

	/* KBE�¼�
	*/
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "KBEngine")
	void onCreateAvatarResult(const UKBEventData* pEventData);

	/* KBE�¼�
	*/
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "KBEngine")
	void addSpaceGeometryMapping(const UKBEventData* pEventData);

	/* KBE�¼�
	*/
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "KBEngine")
	void onRemoveAvatar(const UKBEventData* pEventData);

	UFUNCTION(BlueprintCallable, Category = KBEngine)
	void reqCreateAvatar(uint8 roleType, const FString& name);

	UFUNCTION(BlueprintCallable, Category = KBEngine)
	void reqRemoveAvatar(const FAVATAR_INFOS& avatarInfos);

	UFUNCTION(BlueprintCallable, Category = KBEngine)
	void selectAvatarGame(const FAVATAR_INFOS& avatarInfos);

};
