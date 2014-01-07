#include <hxcpp.h>

#ifndef INCLUDED_Reflect
#include <Reflect.h>
#endif
#ifndef INCLUDED_motion_Actuate
#include <motion/Actuate.h>
#endif
#ifndef INCLUDED_motion_actuators_GenericActuator
#include <motion/actuators/GenericActuator.h>
#endif
#ifndef INCLUDED_motion_actuators_IGenericActuator
#include <motion/actuators/IGenericActuator.h>
#endif
#ifndef INCLUDED_motion_easing_IEasing
#include <motion/easing/IEasing.h>
#endif
namespace motion{
namespace actuators{

Void GenericActuator_obj::__construct(Dynamic target,Float duration,Dynamic properties)
{
HX_STACK_PUSH("GenericActuator::new","motion/actuators/GenericActuator.hx",40);
{
	HX_STACK_LINE(42)
	this->_autoVisible = true;
	HX_STACK_LINE(43)
	this->_delay = (int)0;
	HX_STACK_LINE(44)
	this->_reflect = false;
	HX_STACK_LINE(45)
	this->_repeat = (int)0;
	HX_STACK_LINE(46)
	this->_reverse = false;
	HX_STACK_LINE(47)
	this->_smartRotation = false;
	HX_STACK_LINE(48)
	this->_snapping = false;
	HX_STACK_LINE(49)
	this->special = false;
	HX_STACK_LINE(51)
	this->target = target;
	HX_STACK_LINE(52)
	this->properties = properties;
	HX_STACK_LINE(53)
	this->duration = duration;
	HX_STACK_LINE(55)
	this->_ease = ::motion::Actuate_obj::defaultEase;
}
;
	return null();
}

GenericActuator_obj::~GenericActuator_obj() { }

Dynamic GenericActuator_obj::__CreateEmpty() { return  new GenericActuator_obj; }
hx::ObjectPtr< GenericActuator_obj > GenericActuator_obj::__new(Dynamic target,Float duration,Dynamic properties)
{  hx::ObjectPtr< GenericActuator_obj > result = new GenericActuator_obj();
	result->__construct(target,duration,properties);
	return result;}

Dynamic GenericActuator_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< GenericActuator_obj > result = new GenericActuator_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}

hx::Object *GenericActuator_obj::__ToInterface(const hx::type_info &inType) {
	if (inType==typeid( ::motion::actuators::IGenericActuator_obj)) return operator ::motion::actuators::IGenericActuator_obj *();
	return super::__ToInterface(inType);
}

Void GenericActuator_obj::stop( Dynamic properties,bool complete,bool sendEvent){
{
		HX_STACK_PUSH("GenericActuator::stop","motion/actuators/GenericActuator.hx",402);
		HX_STACK_THIS(this);
		HX_STACK_ARG(properties,"properties");
		HX_STACK_ARG(complete,"complete");
		HX_STACK_ARG(sendEvent,"sendEvent");
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(GenericActuator_obj,stop,(void))

::motion::actuators::IGenericActuator GenericActuator_obj::snapping( Dynamic value){
	HX_STACK_PUSH("GenericActuator::snapping","motion/actuators/GenericActuator.hx",386);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(388)
	if (((value == null()))){
		HX_STACK_LINE(388)
		value = true;
	}
	HX_STACK_LINE(394)
	this->_snapping = value;
	HX_STACK_LINE(395)
	this->special = true;
	HX_STACK_LINE(397)
	return hx::ObjectPtr<OBJ_>(this);
}


HX_DEFINE_DYNAMIC_FUNC1(GenericActuator_obj,snapping,return )

::motion::actuators::IGenericActuator GenericActuator_obj::smartRotation( Dynamic value){
	HX_STACK_PUSH("GenericActuator::smartRotation","motion/actuators/GenericActuator.hx",365);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(367)
	if (((value == null()))){
		HX_STACK_LINE(367)
		value = true;
	}
	HX_STACK_LINE(373)
	this->_smartRotation = value;
	HX_STACK_LINE(374)
	this->special = true;
	HX_STACK_LINE(376)
	return hx::ObjectPtr<OBJ_>(this);
}


HX_DEFINE_DYNAMIC_FUNC1(GenericActuator_obj,smartRotation,return )

::motion::actuators::IGenericActuator GenericActuator_obj::reverse( Dynamic value){
	HX_STACK_PUSH("GenericActuator::reverse","motion/actuators/GenericActuator.hx",344);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(346)
	if (((value == null()))){
		HX_STACK_LINE(346)
		value = true;
	}
	HX_STACK_LINE(352)
	this->_reverse = value;
	HX_STACK_LINE(353)
	this->special = true;
	HX_STACK_LINE(355)
	return hx::ObjectPtr<OBJ_>(this);
}


HX_DEFINE_DYNAMIC_FUNC1(GenericActuator_obj,reverse,return )

Void GenericActuator_obj::resume( ){
{
		HX_STACK_PUSH("GenericActuator::resume","motion/actuators/GenericActuator.hx",332);
		HX_STACK_THIS(this);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(GenericActuator_obj,resume,(void))

::motion::actuators::IGenericActuator GenericActuator_obj::repeat( Dynamic times){
	HX_STACK_PUSH("GenericActuator::repeat","motion/actuators/GenericActuator.hx",317);
	HX_STACK_THIS(this);
	HX_STACK_ARG(times,"times");
	HX_STACK_LINE(319)
	if (((times == null()))){
		HX_STACK_LINE(319)
		times = (int)-1;
	}
	HX_STACK_LINE(325)
	this->_repeat = times;
	HX_STACK_LINE(327)
	return hx::ObjectPtr<OBJ_>(this);
}


HX_DEFINE_DYNAMIC_FUNC1(GenericActuator_obj,repeat,return )

::motion::actuators::IGenericActuator GenericActuator_obj::reflect( Dynamic value){
	HX_STACK_PUSH("GenericActuator::reflect","motion/actuators/GenericActuator.hx",296);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(298)
	if (((value == null()))){
		HX_STACK_LINE(298)
		value = true;
	}
	HX_STACK_LINE(304)
	this->_reflect = value;
	HX_STACK_LINE(305)
	this->special = true;
	HX_STACK_LINE(307)
	return hx::ObjectPtr<OBJ_>(this);
}


HX_DEFINE_DYNAMIC_FUNC1(GenericActuator_obj,reflect,return )

Void GenericActuator_obj::pause( ){
{
		HX_STACK_PUSH("GenericActuator::pause","motion/actuators/GenericActuator.hx",284);
		HX_STACK_THIS(this);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(GenericActuator_obj,pause,(void))

::motion::actuators::IGenericActuator GenericActuator_obj::onUpdate( Dynamic handler,Dynamic parameters){
	HX_STACK_PUSH("GenericActuator::onUpdate","motion/actuators/GenericActuator.hx",265);
	HX_STACK_THIS(this);
	HX_STACK_ARG(handler,"handler");
	HX_STACK_ARG(parameters,"parameters");
	HX_STACK_LINE(267)
	this->_onUpdate = handler;
	HX_STACK_LINE(269)
	if (((parameters == null()))){
		HX_STACK_LINE(269)
		this->_onUpdateParams = Dynamic( Array_obj<Dynamic>::__new());
	}
	else{
		HX_STACK_LINE(273)
		this->_onUpdateParams = parameters;
	}
	HX_STACK_LINE(279)
	return hx::ObjectPtr<OBJ_>(this);
}


HX_DEFINE_DYNAMIC_FUNC2(GenericActuator_obj,onUpdate,return )

::motion::actuators::IGenericActuator GenericActuator_obj::onRepeat( Dynamic handler,Dynamic parameters){
	HX_STACK_PUSH("GenericActuator::onRepeat","motion/actuators/GenericActuator.hx",240);
	HX_STACK_THIS(this);
	HX_STACK_ARG(handler,"handler");
	HX_STACK_ARG(parameters,"parameters");
	HX_STACK_LINE(242)
	this->_onRepeat = handler;
	HX_STACK_LINE(244)
	if (((parameters == null()))){
		HX_STACK_LINE(244)
		this->_onRepeatParams = Dynamic( Array_obj<Dynamic>::__new());
	}
	else{
		HX_STACK_LINE(248)
		this->_onRepeatParams = parameters;
	}
	HX_STACK_LINE(254)
	return hx::ObjectPtr<OBJ_>(this);
}


HX_DEFINE_DYNAMIC_FUNC2(GenericActuator_obj,onRepeat,return )

::motion::actuators::IGenericActuator GenericActuator_obj::onComplete( Dynamic handler,Dynamic parameters){
	HX_STACK_PUSH("GenericActuator::onComplete","motion/actuators/GenericActuator.hx",209);
	HX_STACK_THIS(this);
	HX_STACK_ARG(handler,"handler");
	HX_STACK_ARG(parameters,"parameters");
	HX_STACK_LINE(211)
	this->_onComplete = handler;
	HX_STACK_LINE(213)
	if (((parameters == null()))){
		HX_STACK_LINE(213)
		this->_onCompleteParams = Dynamic( Array_obj<Dynamic>::__new());
	}
	else{
		HX_STACK_LINE(217)
		this->_onCompleteParams = parameters;
	}
	HX_STACK_LINE(223)
	if (((this->duration == (int)0))){
		HX_STACK_LINE(223)
		this->complete(null());
	}
	HX_STACK_LINE(229)
	return hx::ObjectPtr<OBJ_>(this);
}


HX_DEFINE_DYNAMIC_FUNC2(GenericActuator_obj,onComplete,return )

Void GenericActuator_obj::move( ){
{
		HX_STACK_PUSH("GenericActuator::move","motion/actuators/GenericActuator.hx",196);
		HX_STACK_THIS(this);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(GenericActuator_obj,move,(void))

::motion::actuators::IGenericActuator GenericActuator_obj::ease( ::motion::easing::IEasing easing){
	HX_STACK_PUSH("GenericActuator::ease","motion/actuators/GenericActuator.hx",187);
	HX_STACK_THIS(this);
	HX_STACK_ARG(easing,"easing");
	HX_STACK_LINE(189)
	this->_ease = easing;
	HX_STACK_LINE(191)
	return hx::ObjectPtr<OBJ_>(this);
}


HX_DEFINE_DYNAMIC_FUNC1(GenericActuator_obj,ease,return )

::motion::actuators::IGenericActuator GenericActuator_obj::delay( Float duration){
	HX_STACK_PUSH("GenericActuator::delay","motion/actuators/GenericActuator.hx",173);
	HX_STACK_THIS(this);
	HX_STACK_ARG(duration,"duration");
	HX_STACK_LINE(175)
	this->_delay = duration;
	HX_STACK_LINE(177)
	return hx::ObjectPtr<OBJ_>(this);
}


HX_DEFINE_DYNAMIC_FUNC1(GenericActuator_obj,delay,return )

Void GenericActuator_obj::complete( hx::Null< bool >  __o_sendEvent){
bool sendEvent = __o_sendEvent.Default(true);
	HX_STACK_PUSH("GenericActuator::complete","motion/actuators/GenericActuator.hx",149);
	HX_STACK_THIS(this);
	HX_STACK_ARG(sendEvent,"sendEvent");
{
		HX_STACK_LINE(151)
		if ((sendEvent)){
			HX_STACK_LINE(153)
			this->change();
			HX_STACK_LINE(155)
			if (((this->_onComplete != null()))){
				HX_STACK_LINE(157)
				Dynamic method = this->_onComplete;		HX_STACK_VAR(method,"method");
				Dynamic params = this->_onCompleteParams;		HX_STACK_VAR(params,"params");
				HX_STACK_LINE(157)
				if (((params == null()))){
					HX_STACK_LINE(157)
					params = Dynamic( Array_obj<Dynamic>::__new());
				}
				HX_STACK_LINE(157)
				::Reflect_obj::callMethod(method,method,params);
			}
		}
		HX_STACK_LINE(163)
		::motion::Actuate_obj::unload(hx::ObjectPtr<OBJ_>(this));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(GenericActuator_obj,complete,(void))

Void GenericActuator_obj::change( ){
{
		HX_STACK_PUSH("GenericActuator::change","motion/actuators/GenericActuator.hx",138);
		HX_STACK_THIS(this);
		HX_STACK_LINE(138)
		if (((this->_onUpdate != null()))){
			HX_STACK_LINE(142)
			Dynamic method = this->_onUpdate;		HX_STACK_VAR(method,"method");
			Dynamic params = this->_onUpdateParams;		HX_STACK_VAR(params,"params");
			HX_STACK_LINE(142)
			if (((params == null()))){
				HX_STACK_LINE(142)
				params = Dynamic( Array_obj<Dynamic>::__new());
			}
			HX_STACK_LINE(142)
			::Reflect_obj::callMethod(method,method,params);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(GenericActuator_obj,change,(void))

Dynamic GenericActuator_obj::callMethod( Dynamic method,Dynamic params){
	HX_STACK_PUSH("GenericActuator::callMethod","motion/actuators/GenericActuator.hx",107);
	HX_STACK_THIS(this);
	HX_STACK_ARG(method,"method");
	HX_STACK_ARG(params,"params");
	HX_STACK_LINE(109)
	if (((params == null()))){
		HX_STACK_LINE(109)
		params = Dynamic( Array_obj<Dynamic>::__new());
	}
	HX_STACK_LINE(133)
	return ::Reflect_obj::callMethod(method,method,params);
}


HX_DEFINE_DYNAMIC_FUNC2(GenericActuator_obj,callMethod,return )

::motion::actuators::IGenericActuator GenericActuator_obj::autoVisible( Dynamic value){
	HX_STACK_PUSH("GenericActuator::autoVisible","motion/actuators/GenericActuator.hx",92);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(94)
	if (((value == null()))){
		HX_STACK_LINE(94)
		value = true;
	}
	HX_STACK_LINE(100)
	this->_autoVisible = value;
	HX_STACK_LINE(102)
	return hx::ObjectPtr<OBJ_>(this);
}


HX_DEFINE_DYNAMIC_FUNC1(GenericActuator_obj,autoVisible,return )

Void GenericActuator_obj::apply( ){
{
		HX_STACK_PUSH("GenericActuator::apply","motion/actuators/GenericActuator.hx",60);
		HX_STACK_THIS(this);
		HX_STACK_LINE(62)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		Array< ::String > _g1 = ::Reflect_obj::fields(this->properties);		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(62)
		while(((_g < _g1->length))){
			HX_STACK_LINE(62)
			::String i = _g1->__get(_g);		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(62)
			++(_g);
			HX_STACK_LINE(66)
			if ((::Reflect_obj::hasField(this->target,i))){
				HX_STACK_LINE(68)
				Dynamic o = this->target;		HX_STACK_VAR(o,"o");
				HX_STACK_LINE(68)
				if (((o != null()))){
					HX_STACK_LINE(68)
					o->__SetField(i,::Reflect_obj::field(this->properties,i),false);
				}
			}
			else{
				HX_STACK_LINE(72)
				Dynamic o = this->target;		HX_STACK_VAR(o,"o");
				HX_STACK_LINE(72)
				if (((o != null()))){
					HX_STACK_LINE(72)
					o->__SetField(i,::Reflect_obj::field(this->properties,i),true);
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(GenericActuator_obj,apply,(void))


GenericActuator_obj::GenericActuator_obj()
{
}

void GenericActuator_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(GenericActuator);
	HX_MARK_MEMBER_NAME(special,"special");
	HX_MARK_MEMBER_NAME(_snapping,"_snapping");
	HX_MARK_MEMBER_NAME(_smartRotation,"_smartRotation");
	HX_MARK_MEMBER_NAME(_reverse,"_reverse");
	HX_MARK_MEMBER_NAME(_repeat,"_repeat");
	HX_MARK_MEMBER_NAME(_reflect,"_reflect");
	HX_MARK_MEMBER_NAME(_onUpdateParams,"_onUpdateParams");
	HX_MARK_MEMBER_NAME(_onUpdate,"_onUpdate");
	HX_MARK_MEMBER_NAME(_onRepeatParams,"_onRepeatParams");
	HX_MARK_MEMBER_NAME(_onRepeat,"_onRepeat");
	HX_MARK_MEMBER_NAME(_onCompleteParams,"_onCompleteParams");
	HX_MARK_MEMBER_NAME(_onComplete,"_onComplete");
	HX_MARK_MEMBER_NAME(_ease,"_ease");
	HX_MARK_MEMBER_NAME(_delay,"_delay");
	HX_MARK_MEMBER_NAME(_autoVisible,"_autoVisible");
	HX_MARK_MEMBER_NAME(target,"target");
	HX_MARK_MEMBER_NAME(properties,"properties");
	HX_MARK_MEMBER_NAME(id,"id");
	HX_MARK_MEMBER_NAME(duration,"duration");
	HX_MARK_END_CLASS();
}

void GenericActuator_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(special,"special");
	HX_VISIT_MEMBER_NAME(_snapping,"_snapping");
	HX_VISIT_MEMBER_NAME(_smartRotation,"_smartRotation");
	HX_VISIT_MEMBER_NAME(_reverse,"_reverse");
	HX_VISIT_MEMBER_NAME(_repeat,"_repeat");
	HX_VISIT_MEMBER_NAME(_reflect,"_reflect");
	HX_VISIT_MEMBER_NAME(_onUpdateParams,"_onUpdateParams");
	HX_VISIT_MEMBER_NAME(_onUpdate,"_onUpdate");
	HX_VISIT_MEMBER_NAME(_onRepeatParams,"_onRepeatParams");
	HX_VISIT_MEMBER_NAME(_onRepeat,"_onRepeat");
	HX_VISIT_MEMBER_NAME(_onCompleteParams,"_onCompleteParams");
	HX_VISIT_MEMBER_NAME(_onComplete,"_onComplete");
	HX_VISIT_MEMBER_NAME(_ease,"_ease");
	HX_VISIT_MEMBER_NAME(_delay,"_delay");
	HX_VISIT_MEMBER_NAME(_autoVisible,"_autoVisible");
	HX_VISIT_MEMBER_NAME(target,"target");
	HX_VISIT_MEMBER_NAME(properties,"properties");
	HX_VISIT_MEMBER_NAME(id,"id");
	HX_VISIT_MEMBER_NAME(duration,"duration");
}

Dynamic GenericActuator_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"id") ) { return id; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"stop") ) { return stop_dyn(); }
		if (HX_FIELD_EQ(inName,"move") ) { return move_dyn(); }
		if (HX_FIELD_EQ(inName,"ease") ) { return ease_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"pause") ) { return pause_dyn(); }
		if (HX_FIELD_EQ(inName,"delay") ) { return delay_dyn(); }
		if (HX_FIELD_EQ(inName,"apply") ) { return apply_dyn(); }
		if (HX_FIELD_EQ(inName,"_ease") ) { return _ease; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"resume") ) { return resume_dyn(); }
		if (HX_FIELD_EQ(inName,"repeat") ) { return repeat_dyn(); }
		if (HX_FIELD_EQ(inName,"change") ) { return change_dyn(); }
		if (HX_FIELD_EQ(inName,"_delay") ) { return _delay; }
		if (HX_FIELD_EQ(inName,"target") ) { return target; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"reverse") ) { return reverse_dyn(); }
		if (HX_FIELD_EQ(inName,"reflect") ) { return reflect_dyn(); }
		if (HX_FIELD_EQ(inName,"special") ) { return special; }
		if (HX_FIELD_EQ(inName,"_repeat") ) { return _repeat; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"snapping") ) { return snapping_dyn(); }
		if (HX_FIELD_EQ(inName,"onUpdate") ) { return onUpdate_dyn(); }
		if (HX_FIELD_EQ(inName,"onRepeat") ) { return onRepeat_dyn(); }
		if (HX_FIELD_EQ(inName,"complete") ) { return complete_dyn(); }
		if (HX_FIELD_EQ(inName,"_reverse") ) { return _reverse; }
		if (HX_FIELD_EQ(inName,"_reflect") ) { return _reflect; }
		if (HX_FIELD_EQ(inName,"duration") ) { return duration; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"_snapping") ) { return _snapping; }
		if (HX_FIELD_EQ(inName,"_onUpdate") ) { return _onUpdate; }
		if (HX_FIELD_EQ(inName,"_onRepeat") ) { return _onRepeat; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"onComplete") ) { return onComplete_dyn(); }
		if (HX_FIELD_EQ(inName,"callMethod") ) { return callMethod_dyn(); }
		if (HX_FIELD_EQ(inName,"properties") ) { return properties; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"autoVisible") ) { return autoVisible_dyn(); }
		if (HX_FIELD_EQ(inName,"_onComplete") ) { return _onComplete; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"_autoVisible") ) { return _autoVisible; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"smartRotation") ) { return smartRotation_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"_smartRotation") ) { return _smartRotation; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"_onUpdateParams") ) { return _onUpdateParams; }
		if (HX_FIELD_EQ(inName,"_onRepeatParams") ) { return _onRepeatParams; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"_onCompleteParams") ) { return _onCompleteParams; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic GenericActuator_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"id") ) { id=inValue.Cast< ::String >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_ease") ) { _ease=inValue.Cast< ::motion::easing::IEasing >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"_delay") ) { _delay=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"target") ) { target=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"special") ) { special=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_repeat") ) { _repeat=inValue.Cast< int >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"_reverse") ) { _reverse=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_reflect") ) { _reflect=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"duration") ) { duration=inValue.Cast< Float >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"_snapping") ) { _snapping=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_onUpdate") ) { _onUpdate=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_onRepeat") ) { _onRepeat=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"properties") ) { properties=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"_onComplete") ) { _onComplete=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"_autoVisible") ) { _autoVisible=inValue.Cast< bool >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"_smartRotation") ) { _smartRotation=inValue.Cast< bool >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"_onUpdateParams") ) { _onUpdateParams=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_onRepeatParams") ) { _onRepeatParams=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"_onCompleteParams") ) { _onCompleteParams=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void GenericActuator_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("special"));
	outFields->push(HX_CSTRING("_snapping"));
	outFields->push(HX_CSTRING("_smartRotation"));
	outFields->push(HX_CSTRING("_reverse"));
	outFields->push(HX_CSTRING("_repeat"));
	outFields->push(HX_CSTRING("_reflect"));
	outFields->push(HX_CSTRING("_onUpdateParams"));
	outFields->push(HX_CSTRING("_onUpdate"));
	outFields->push(HX_CSTRING("_onRepeatParams"));
	outFields->push(HX_CSTRING("_onRepeat"));
	outFields->push(HX_CSTRING("_onCompleteParams"));
	outFields->push(HX_CSTRING("_onComplete"));
	outFields->push(HX_CSTRING("_ease"));
	outFields->push(HX_CSTRING("_delay"));
	outFields->push(HX_CSTRING("_autoVisible"));
	outFields->push(HX_CSTRING("target"));
	outFields->push(HX_CSTRING("properties"));
	outFields->push(HX_CSTRING("id"));
	outFields->push(HX_CSTRING("duration"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("stop"),
	HX_CSTRING("snapping"),
	HX_CSTRING("smartRotation"),
	HX_CSTRING("reverse"),
	HX_CSTRING("resume"),
	HX_CSTRING("repeat"),
	HX_CSTRING("reflect"),
	HX_CSTRING("pause"),
	HX_CSTRING("onUpdate"),
	HX_CSTRING("onRepeat"),
	HX_CSTRING("onComplete"),
	HX_CSTRING("move"),
	HX_CSTRING("ease"),
	HX_CSTRING("delay"),
	HX_CSTRING("complete"),
	HX_CSTRING("change"),
	HX_CSTRING("callMethod"),
	HX_CSTRING("autoVisible"),
	HX_CSTRING("apply"),
	HX_CSTRING("special"),
	HX_CSTRING("_snapping"),
	HX_CSTRING("_smartRotation"),
	HX_CSTRING("_reverse"),
	HX_CSTRING("_repeat"),
	HX_CSTRING("_reflect"),
	HX_CSTRING("_onUpdateParams"),
	HX_CSTRING("_onUpdate"),
	HX_CSTRING("_onRepeatParams"),
	HX_CSTRING("_onRepeat"),
	HX_CSTRING("_onCompleteParams"),
	HX_CSTRING("_onComplete"),
	HX_CSTRING("_ease"),
	HX_CSTRING("_delay"),
	HX_CSTRING("_autoVisible"),
	HX_CSTRING("target"),
	HX_CSTRING("properties"),
	HX_CSTRING("id"),
	HX_CSTRING("duration"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(GenericActuator_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(GenericActuator_obj::__mClass,"__mClass");
};

Class GenericActuator_obj::__mClass;

void GenericActuator_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("motion.actuators.GenericActuator"), hx::TCanCast< GenericActuator_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void GenericActuator_obj::__boot()
{
}

} // end namespace motion
} // end namespace actuators
