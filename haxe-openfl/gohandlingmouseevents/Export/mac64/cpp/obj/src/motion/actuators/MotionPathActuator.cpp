#include <hxcpp.h>

#ifndef INCLUDED_Reflect
#include <Reflect.h>
#endif
#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_motion_IComponentPath
#include <motion/IComponentPath.h>
#endif
#ifndef INCLUDED_motion_actuators_GenericActuator
#include <motion/actuators/GenericActuator.h>
#endif
#ifndef INCLUDED_motion_actuators_IGenericActuator
#include <motion/actuators/IGenericActuator.h>
#endif
#ifndef INCLUDED_motion_actuators_MotionPathActuator
#include <motion/actuators/MotionPathActuator.h>
#endif
#ifndef INCLUDED_motion_actuators_PropertyDetails
#include <motion/actuators/PropertyDetails.h>
#endif
#ifndef INCLUDED_motion_actuators_PropertyPathDetails
#include <motion/actuators/PropertyPathDetails.h>
#endif
#ifndef INCLUDED_motion_actuators_SimpleActuator
#include <motion/actuators/SimpleActuator.h>
#endif
#ifndef INCLUDED_motion_easing_IEasing
#include <motion/easing/IEasing.h>
#endif
namespace motion{
namespace actuators{

Void MotionPathActuator_obj::__construct(Dynamic target,Float duration,Dynamic properties)
{
HX_STACK_PUSH("MotionPathActuator::new","motion/actuators/MotionPathActuator.hx",13);
{
	HX_STACK_LINE(13)
	super::__construct(target,duration,properties);
}
;
	return null();
}

MotionPathActuator_obj::~MotionPathActuator_obj() { }

Dynamic MotionPathActuator_obj::__CreateEmpty() { return  new MotionPathActuator_obj; }
hx::ObjectPtr< MotionPathActuator_obj > MotionPathActuator_obj::__new(Dynamic target,Float duration,Dynamic properties)
{  hx::ObjectPtr< MotionPathActuator_obj > result = new MotionPathActuator_obj();
	result->__construct(target,duration,properties);
	return result;}

Dynamic MotionPathActuator_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< MotionPathActuator_obj > result = new MotionPathActuator_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}

Void MotionPathActuator_obj::update( Float currentTime){
{
		HX_STACK_PUSH("MotionPathActuator::update","motion/actuators/MotionPathActuator.hx",92);
		HX_STACK_THIS(this);
		HX_STACK_ARG(currentTime,"currentTime");
		HX_STACK_LINE(92)
		if ((!(this->paused))){
			HX_STACK_LINE(96)
			::motion::actuators::PropertyPathDetails details;		HX_STACK_VAR(details,"details");
			HX_STACK_LINE(97)
			Float easing;		HX_STACK_VAR(easing,"easing");
			HX_STACK_LINE(99)
			Float tweenPosition = (Float(((currentTime - this->timeOffset))) / Float(this->duration));		HX_STACK_VAR(tweenPosition,"tweenPosition");
			HX_STACK_LINE(101)
			if (((tweenPosition > (int)1))){
				HX_STACK_LINE(101)
				tweenPosition = (int)1;
			}
			HX_STACK_LINE(107)
			if ((!(this->initialized))){
				HX_STACK_LINE(107)
				this->initialize();
			}
			HX_STACK_LINE(113)
			if ((!(this->special))){
				HX_STACK_LINE(115)
				easing = this->_ease->calculate(tweenPosition);
				HX_STACK_LINE(117)
				{
					HX_STACK_LINE(117)
					int _g = (int)0;		HX_STACK_VAR(_g,"_g");
					Array< ::Dynamic > _g1 = this->propertyDetails;		HX_STACK_VAR(_g1,"_g1");
					HX_STACK_LINE(117)
					while(((_g < _g1->length))){
						HX_STACK_LINE(117)
						::motion::actuators::PropertyDetails details1 = _g1->__get(_g).StaticCast< ::motion::actuators::PropertyDetails >();		HX_STACK_VAR(details1,"details1");
						HX_STACK_LINE(117)
						++(_g);
						HX_STACK_LINE(119)
						if ((details1->isField)){
							HX_STACK_LINE(121)
							Dynamic o = details1->target;		HX_STACK_VAR(o,"o");
							HX_STACK_LINE(121)
							if (((o != null()))){
								HX_STACK_LINE(121)
								o->__SetField(details1->propertyName,(hx::TCast< motion::actuators::PropertyPathDetails >::cast(details1))->path->calculate(easing),false);
							}
						}
						else{
							HX_STACK_LINE(126)
							Dynamic o = details1->target;		HX_STACK_VAR(o,"o");
							HX_STACK_LINE(126)
							if (((o != null()))){
								HX_STACK_LINE(126)
								o->__SetField(details1->propertyName,(hx::TCast< motion::actuators::PropertyPathDetails >::cast(details1))->path->calculate(easing),true);
							}
						}
					}
				}
			}
			else{
				HX_STACK_LINE(135)
				if ((!(this->_reverse))){
					HX_STACK_LINE(135)
					easing = this->_ease->calculate(tweenPosition);
				}
				else{
					HX_STACK_LINE(139)
					easing = this->_ease->calculate(((int)1 - tweenPosition));
				}
				HX_STACK_LINE(145)
				Float endValue;		HX_STACK_VAR(endValue,"endValue");
				HX_STACK_LINE(147)
				{
					HX_STACK_LINE(147)
					int _g = (int)0;		HX_STACK_VAR(_g,"_g");
					Array< ::Dynamic > _g1 = this->propertyDetails;		HX_STACK_VAR(_g1,"_g1");
					HX_STACK_LINE(147)
					while(((_g < _g1->length))){
						HX_STACK_LINE(147)
						::motion::actuators::PropertyDetails details1 = _g1->__get(_g).StaticCast< ::motion::actuators::PropertyDetails >();		HX_STACK_VAR(details1,"details1");
						HX_STACK_LINE(147)
						++(_g);
						HX_STACK_LINE(149)
						if ((!(this->_snapping))){
							HX_STACK_LINE(149)
							if ((details1->isField)){
								HX_STACK_LINE(153)
								Dynamic o = details1->target;		HX_STACK_VAR(o,"o");
								HX_STACK_LINE(153)
								if (((o != null()))){
									HX_STACK_LINE(153)
									o->__SetField(details1->propertyName,(hx::TCast< motion::actuators::PropertyPathDetails >::cast(details1))->path->calculate(easing),false);
								}
							}
							else{
								HX_STACK_LINE(158)
								Dynamic o = details1->target;		HX_STACK_VAR(o,"o");
								HX_STACK_LINE(158)
								if (((o != null()))){
									HX_STACK_LINE(158)
									o->__SetField(details1->propertyName,(hx::TCast< motion::actuators::PropertyPathDetails >::cast(details1))->path->calculate(easing),true);
								}
							}
						}
						else{
							HX_STACK_LINE(163)
							if ((details1->isField)){
								HX_STACK_LINE(167)
								Dynamic o = details1->target;		HX_STACK_VAR(o,"o");
								HX_STACK_LINE(167)
								if (((o != null()))){
									HX_STACK_LINE(167)
									o->__SetField(details1->propertyName,::Math_obj::round((hx::TCast< motion::actuators::PropertyPathDetails >::cast(details1))->path->calculate(easing)),false);
								}
							}
							else{
								HX_STACK_LINE(172)
								Dynamic o = details1->target;		HX_STACK_VAR(o,"o");
								HX_STACK_LINE(172)
								if (((o != null()))){
									HX_STACK_LINE(172)
									o->__SetField(details1->propertyName,::Math_obj::round((hx::TCast< motion::actuators::PropertyPathDetails >::cast(details1))->path->calculate(easing)),true);
								}
							}
						}
					}
				}
			}
			HX_STACK_LINE(184)
			if (((tweenPosition == (int)1))){
				HX_STACK_LINE(184)
				if (((this->_repeat == (int)0))){
					HX_STACK_LINE(188)
					this->active = false;
					struct _Function_4_1{
						inline static Dynamic Block( ::motion::actuators::MotionPathActuator_obj *__this){
							HX_STACK_PUSH("*::closure","motion/actuators/MotionPathActuator.hx",190);
							{
								HX_STACK_LINE(190)
								Dynamic target = __this->target;		HX_STACK_VAR(target,"target");
								HX_STACK_LINE(190)
								Dynamic value = null();		HX_STACK_VAR(value,"value");
								HX_STACK_LINE(190)
								if ((::Reflect_obj::hasField(target,HX_CSTRING("alpha")))){
									HX_STACK_LINE(190)
									value = ::Reflect_obj::field(target,HX_CSTRING("alpha"));
								}
								else{
									HX_STACK_LINE(190)
									value = (  (((target == null()))) ? Dynamic(null()) : Dynamic(target->__Field(HX_CSTRING("alpha"),true)) );
								}
								HX_STACK_LINE(190)
								return value;
							}
							return null();
						}
					};
					HX_STACK_LINE(190)
					if (((bool(this->toggleVisible) && bool((_Function_4_1::Block(this) == (int)0))))){
						HX_STACK_LINE(192)
						Dynamic target = this->target;		HX_STACK_VAR(target,"target");
						HX_STACK_LINE(192)
						if ((::Reflect_obj::hasField(target,HX_CSTRING("visible")))){
							HX_STACK_LINE(192)
							if (((target != null()))){
								HX_STACK_LINE(192)
								target->__SetField(HX_CSTRING("visible"),false,false);
							}
						}
						else{
							HX_STACK_LINE(192)
							if (((target != null()))){
								HX_STACK_LINE(192)
								target->__SetField(HX_CSTRING("visible"),false,true);
							}
						}
					}
					HX_STACK_LINE(196)
					this->complete(true);
					HX_STACK_LINE(197)
					return null();
				}
				else{
					HX_STACK_LINE(201)
					if ((this->_reflect)){
						HX_STACK_LINE(201)
						this->_reverse = !(this->_reverse);
					}
					HX_STACK_LINE(207)
					this->startTime = currentTime;
					HX_STACK_LINE(208)
					this->timeOffset = (this->startTime + this->_delay);
					HX_STACK_LINE(210)
					if (((this->_repeat > (int)0))){
						HX_STACK_LINE(210)
						(this->_repeat)--;
					}
				}
			}
			HX_STACK_LINE(220)
			if ((this->sendChange)){
				HX_STACK_LINE(220)
				this->change();
			}
		}
	}
return null();
}


Void MotionPathActuator_obj::initialize( ){
{
		HX_STACK_PUSH("MotionPathActuator::initialize","motion/actuators/MotionPathActuator.hx",47);
		HX_STACK_THIS(this);
		HX_STACK_LINE(49)
		::motion::actuators::PropertyPathDetails details;		HX_STACK_VAR(details,"details");
		HX_STACK_LINE(50)
		::motion::IComponentPath path;		HX_STACK_VAR(path,"path");
		HX_STACK_LINE(52)
		{
			HX_STACK_LINE(52)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			Array< ::String > _g1 = ::Reflect_obj::fields(this->properties);		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(52)
			while(((_g < _g1->length))){
				HX_STACK_LINE(52)
				::String propertyName = _g1->__get(_g);		HX_STACK_VAR(propertyName,"propertyName");
				HX_STACK_LINE(52)
				++(_g);
				HX_STACK_LINE(54)
				path = hx::TCast< motion::IComponentPath >::cast(::Reflect_obj::field(this->properties,propertyName));
				HX_STACK_LINE(56)
				if (((path != null()))){
					HX_STACK_LINE(58)
					bool isField = true;		HX_STACK_VAR(isField,"isField");
					HX_STACK_LINE(62)
					if ((::Reflect_obj::hasField(this->target,propertyName))){
						HX_STACK_LINE(62)
						path->__FieldRef(HX_CSTRING("start")) = ::Reflect_obj::field(this->target,propertyName);
					}
					else{
						HX_STACK_LINE(68)
						isField = false;
						struct _Function_5_1{
							inline static Dynamic Block( ::motion::actuators::MotionPathActuator_obj *__this,::String &propertyName){
								HX_STACK_PUSH("*::closure","motion/actuators/MotionPathActuator.hx",69);
								{
									HX_STACK_LINE(69)
									Dynamic o = __this->target;		HX_STACK_VAR(o,"o");
									HX_STACK_LINE(69)
									return (  (((o == null()))) ? Dynamic(null()) : Dynamic(o->__Field(propertyName,true)) );
								}
								return null();
							}
						};
						HX_STACK_LINE(69)
						path->__FieldRef(HX_CSTRING("start")) = _Function_5_1::Block(this,propertyName);
					}
					HX_STACK_LINE(79)
					details = ::motion::actuators::PropertyPathDetails_obj::__new(this->target,propertyName,path,isField);
					HX_STACK_LINE(80)
					this->propertyDetails->push(details);
				}
			}
		}
		HX_STACK_LINE(86)
		this->detailsLength = this->propertyDetails->length;
		HX_STACK_LINE(87)
		this->initialized = true;
	}
return null();
}


Void MotionPathActuator_obj::apply( ){
{
		HX_STACK_PUSH("MotionPathActuator::apply","motion/actuators/MotionPathActuator.hx",20);
		HX_STACK_THIS(this);
		HX_STACK_LINE(22)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		Array< ::String > _g1 = ::Reflect_obj::fields(this->properties);		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(22)
		while(((_g < _g1->length))){
			HX_STACK_LINE(22)
			::String propertyName = _g1->__get(_g);		HX_STACK_VAR(propertyName,"propertyName");
			HX_STACK_LINE(22)
			++(_g);
			HX_STACK_LINE(26)
			if ((::Reflect_obj::hasField(this->target,propertyName))){
				HX_STACK_LINE(28)
				Dynamic o = this->target;		HX_STACK_VAR(o,"o");
				HX_STACK_LINE(28)
				if (((o != null()))){
					HX_STACK_LINE(28)
					o->__SetField(propertyName,(hx::TCast< motion::IComponentPath >::cast(::Reflect_obj::field(this->properties,propertyName)))->__Field(HX_CSTRING("get_end"),true)(),false);
				}
			}
			else{
				HX_STACK_LINE(32)
				Dynamic o = this->target;		HX_STACK_VAR(o,"o");
				HX_STACK_LINE(32)
				if (((o != null()))){
					HX_STACK_LINE(32)
					o->__SetField(propertyName,(hx::TCast< motion::IComponentPath >::cast(::Reflect_obj::field(this->properties,propertyName)))->__Field(HX_CSTRING("get_end"),true)(),true);
				}
			}
		}
	}
return null();
}



MotionPathActuator_obj::MotionPathActuator_obj()
{
}

void MotionPathActuator_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(MotionPathActuator);
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void MotionPathActuator_obj::__Visit(HX_VISIT_PARAMS)
{
	super::__Visit(HX_VISIT_ARG);
}

Dynamic MotionPathActuator_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"apply") ) { return apply_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"initialize") ) { return initialize_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic MotionPathActuator_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void MotionPathActuator_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("update"),
	HX_CSTRING("initialize"),
	HX_CSTRING("apply"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(MotionPathActuator_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(MotionPathActuator_obj::__mClass,"__mClass");
};

Class MotionPathActuator_obj::__mClass;

void MotionPathActuator_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("motion.actuators.MotionPathActuator"), hx::TCanCast< MotionPathActuator_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void MotionPathActuator_obj::__boot()
{
}

} // end namespace motion
} // end namespace actuators
