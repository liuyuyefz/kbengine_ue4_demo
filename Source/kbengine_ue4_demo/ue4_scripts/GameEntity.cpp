// Fill out your copyright notice in the Description page of Project Settings.

#include "kbengine_ue4_demo.h"
#include "GameEntity.h"
#include "GameModeWorld.h"
#include "KBEngine.h"
#include "Entity.h"

// Sets default values
AGameEntity::AGameEntity(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	entityID = 0;
	moveSpeed = 0.f;
}

// Called when the game starts or when spawned
void AGameEntity::BeginPlay()
{
	Super::BeginPlay();
	
	auto XGameMode = Cast<AGameModeWorld>(UGameplayStatics::GetGameMode(this));
	
	if (XGameMode)
	{
		// 把自己注册到AGameModeWorld，方便后面查找
		XGameMode->addGameEntity(this->entityID, this);

		Entity* pEntity = KBEngineApp::getSingleton().findEntity(entityID);

		// 由于UE4可视化实体创建要晚于KBE的插件的逻辑实体，而KBE插件实体先前可能已经触发了一些属性设置事件
		// 因此此时我们可能已经错过了一些事件，我们只能在此补救必要的触发了， 例如：名称和血量属性值
		if (pEntity)
			pEntity->callPropertysSetMethods();
	}
}

void AGameEntity::Destroyed()
{
	Super::Destroyed();

	auto XGameMode = Cast<AGameModeWorld>(UGameplayStatics::GetGameMode(this));

	if (XGameMode)
	{
		// 把自己注册到AGameModeWorld，方便后面查找
		XGameMode->removeGameEntity(this->entityID);
	}
}

void AGameEntity::updateLocation(float DeltaTime)
{
	const FVector& currLocation = GetActorLocation();

	//Direction from Self to targetPos
	FVector vectorDirection = targetLocation - currLocation;

	float deltaSpeed = (moveSpeed * 10.f /*由于服务端脚本moveSpeed的单位是厘米，这里需要转换为UE4单位毫米*/) * DeltaTime;
	if (vectorDirection.Size() > deltaSpeed)
	{
		//Normalize Vector so it is just a direction
		vectorDirection.Normalize();

		//Move moveSpeed units toward the player, per tick
		SetActorLocation(currLocation + (vectorDirection * deltaSpeed));
	}
	else
	{
		SetActorLocation(targetLocation);
	}

	FaceRotation(targetRotator);
}

// Called every frame
void AGameEntity::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

	if (!isPlayer())
	{
		updateLocation(DeltaTime);
	}
}

// Called to bind functionality to input
void AGameEntity::SetupPlayerInputComponent(class UInputComponent* inputComponent)
{
	Super::SetupPlayerInputComponent(inputComponent);

}

void AGameEntity::FaceRotation(FRotator NewRotation, float DeltaTime)
{
	FRotator CurrentRotation = FMath::RInterpTo(GetActorRotation(), NewRotation, DeltaTime, 8.0f);

	Super::FaceRotation(CurrentRotation, DeltaTime);
}

