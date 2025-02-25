// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#pragma once
#include "KBECommon.h"

class GameObject;
class NPCObject;
class Motion;

/*
	对应entity_defs/*

	要实现一个KBE对应的实体必须经过以下几步
	1: 在服务器entity_defs中entities.xml中注册实体并实现实体的def定义
	2: 在服务器的相关位置如：assets/scripts目录的cell（ 取决于实体拥有该部分）或base（ 取决于实体拥有该部分）文件夹下实现实体的服务器部分py脚本模块
	3: 在UE4客户端中kbe_scripts文件夹下实现实体的客户端部分脚本模块（这里统一称为实体脚本，虽然是C++实现），UE4实现实体后必须有如下几步
		A：在实体的头文件中按照格式定义ENTITYDEF_DECLARE_模块名， 具体看demo
		B：在实体CPP文件中ENTITYDEF_CLASS_REGISTER将实体注册，具体看demo
*/
class NPC : public GameObject, public NPCObject, public Motion
{
public:
	NPC();
	virtual ~NPC();

public:
	// def中定义的客户端涉及属性
};

/*
Declare all of the properties and methods of the KBE-Entity

Example:
	#define ENTITYDEF_DECLARE_[module name of Entity](PARENT_MODULE)	\
		ENTITYDEF_PROPERTY_*(PARENT_MODULE, xx_property)	\
		ENTITYDEF_METHOD_ARGS[0~20]_REGISTER(PARENT_MODULE, xx_method)
*/

#define ENTITYDEF_DECLARE_NPC(PARENT_MODULE)	