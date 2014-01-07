#include <hxcpp.h>

#ifndef INCLUDED_Reflect
#include <Reflect.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_flash_display_DisplayObject
#include <flash/display/DisplayObject.h>
#endif
#ifndef INCLUDED_flash_display_IBitmapDrawable
#include <flash/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_flash_events_EventDispatcher
#include <flash/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_flash_events_IEventDispatcher
#include <flash/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_flash_filters_BitmapFilter
#include <flash/filters/BitmapFilter.h>
#endif
#ifndef INCLUDED_motion_actuators_FilterActuator
#include <motion/actuators/FilterActuator.h>
#endif
#ifndef INCLUDED_motion_actuators_GenericActuator
#include <motion/actuators/GenericActuator.h>
#endif
#ifndef INCLUDED_motion_actuators_IGenericActuator
#include <motion/actuators/IGenericActuator.h>
#endif
#ifndef INCLUDED_motion_actuators_PropertyDetails
#include <motion/actuators/PropertyDetails.h>
#endif
#ifndef INCLUDED_motion_actuators_SimpleActuator
#include <motion/actuators/SimpleActuator.h>
#endif
namespace motion{
namespace actuators{

Void FilterActuator_obj::__construct(Dynamic target,Float duration,Dynamic properties)
{
HX_STACK_PUSH("FilterActuator::new","motion/actuators/FilterActuator.hx",21);
{
	HX_STACK_LINE(23)
	this->filterIndex = (int)-1;
	HX_STACK_LINE(25)
	super::__construct(target,duration,properties);
	HX_STACK_LINE(27)
	if ((::Std_obj::is(properties->__Field(HX_CSTRING("filter"),true),hx::ClassOf< ::Class >()))){
		HX_STACK_LINE(29)
		this->filterClass = properties->__Field(HX_CSTRING("filter"),true);
		HX_STACK_LINE(31)
		{
			HX_STACK_LINE(31)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			Dynamic _g1 = (hx::TCast< flash::display::DisplayObject >::cast(target))->get_filters();		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(31)
			while(((_g < _g1->__Field(HX_CSTRING("length"),true)))){
				HX_STACK_LINE(31)
				Dynamic filter = _g1->__GetItem(_g);		HX_STACK_VAR(filter,"filter");
				HX_STACK_LINE(31)
				++(_g);
				HX_STACK_LINE(33)
				if ((::Std_obj::is(filter,this->filterClass))){
					HX_STACK_LINE(33)
					this->filter = filter;
				}
			}
		}
	}
	else{
		HX_STACK_LINE(43)
		this->filterIndex = properties->__Field(HX_CSTRING("filter"),true);
		HX_STACK_LINE(44)
		this->filter = (hx::TCast< flash::display::DisplayObject >::cast(target))->get_filters()->__GetItem(this->filterIndex);
	}
}
;
	return null();
}

FilterActuator_obj::~FilterActuator_obj() { }

Dynamic FilterActuator_obj::__CreateEmpty() { return  new FilterActuator_obj; }
hx::ObjectPtr< FilterActuator_obj > FilterActuator_obj::__new(Dynamic target,Float duration,Dynamic properties)
{  hx::ObjectPtr< FilterActuator_obj > result = new FilterActuator_obj();
	result->__construct(target,duration,properties);
	return result;}

Dynamic FilterActuator_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< FilterActuator_obj > result = new FilterActuator_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}

Void FilterActuator_obj::update( Float currentTime){
{
		HX_STACK_PUSH("FilterActuator::update","motion/actuators/FilterActuator.hx",93);
		HX_STACK_THIS(this);
		HX_STACK_ARG(currentTime,"currentTime");
		HX_STACK_LINE(95)
		this->super::update(currentTime);
		HX_STACK_LINE(97)
		Dynamic filters = (hx::TCast< flash::display::DisplayObject >::cast(this->target))->get_filters();		HX_STACK_VAR(filters,"filters");
		HX_STACK_LINE(99)
		if (((this->filterIndex > (int)-1))){
			HX_STACK_LINE(101)
			::String field = this->properties->__Field(HX_CSTRING("filter"),true);		HX_STACK_VAR(field,"field");
			HX_STACK_LINE(101)
			if (((filters != null()))){
				HX_STACK_LINE(101)
				filters->__SetField(field,this->filter,false);
			}
		}
		else{
			HX_STACK_LINE(105)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			int _g = filters->__Field(HX_CSTRING("length"),true);		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(105)
			while(((_g1 < _g))){
				HX_STACK_LINE(105)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(107)
				if ((::Std_obj::is(filters->__GetItem(i),this->filterClass))){
					HX_STACK_LINE(107)
					hx::IndexRef((filters).mPtr,i) = this->filter;
				}
			}
		}
		HX_STACK_LINE(117)
		{
			HX_STACK_LINE(117)
			Dynamic target = this->target;		HX_STACK_VAR(target,"target");
			HX_STACK_LINE(117)
			if ((::Reflect_obj::hasField(target,HX_CSTRING("filters")))){
				HX_STACK_LINE(117)
				if (((target != null()))){
					HX_STACK_LINE(117)
					target->__SetField(HX_CSTRING("filters"),filters,false);
				}
			}
			else{
				HX_STACK_LINE(117)
				if (((target != null()))){
					HX_STACK_LINE(117)
					target->__SetField(HX_CSTRING("filters"),filters,true);
				}
			}
		}
	}
return null();
}


Void FilterActuator_obj::initialize( ){
{
		HX_STACK_PUSH("FilterActuator::initialize","motion/actuators/FilterActuator.hx",70);
		HX_STACK_THIS(this);
		HX_STACK_LINE(72)
		::motion::actuators::PropertyDetails details;		HX_STACK_VAR(details,"details");
		HX_STACK_LINE(73)
		Float start;		HX_STACK_VAR(start,"start");
		HX_STACK_LINE(75)
		{
			HX_STACK_LINE(75)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			Array< ::String > _g1 = ::Reflect_obj::fields(this->properties);		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(75)
			while(((_g < _g1->length))){
				HX_STACK_LINE(75)
				::String propertyName = _g1->__get(_g);		HX_STACK_VAR(propertyName,"propertyName");
				HX_STACK_LINE(75)
				++(_g);
				HX_STACK_LINE(77)
				if (((propertyName != HX_CSTRING("filter")))){
					struct _Function_4_1{
						inline static Dynamic Block( ::motion::actuators::FilterActuator_obj *__this,::String &propertyName){
							HX_STACK_PUSH("*::closure","motion/actuators/FilterActuator.hx",79);
							{
								HX_STACK_LINE(79)
								Dynamic target = __this->filter;		HX_STACK_VAR(target,"target");
								HX_STACK_LINE(79)
								Dynamic value = null();		HX_STACK_VAR(value,"value");
								HX_STACK_LINE(79)
								if ((::Reflect_obj::hasField(target,propertyName))){
									HX_STACK_LINE(79)
									value = ::Reflect_obj::field(target,propertyName);
								}
								else{
									HX_STACK_LINE(79)
									value = (  (((target == null()))) ? Dynamic(null()) : Dynamic(target->__Field(propertyName,true)) );
								}
								HX_STACK_LINE(79)
								return value;
							}
							return null();
						}
					};
					HX_STACK_LINE(79)
					start = _Function_4_1::Block(this,propertyName);
					HX_STACK_LINE(80)
					details = ::motion::actuators::PropertyDetails_obj::__new(this->filter,propertyName,start,(::Reflect_obj::field(this->properties,propertyName) - start),null());
					HX_STACK_LINE(81)
					this->propertyDetails->push(details);
				}
			}
		}
		HX_STACK_LINE(87)
		this->detailsLength = this->propertyDetails->length;
		HX_STACK_LINE(88)
		this->initialized = true;
	}
return null();
}


Void FilterActuator_obj::apply( ){
{
		HX_STACK_PUSH("FilterActuator::apply","motion/actuators/FilterActuator.hx",51);
		HX_STACK_THIS(this);
		HX_STACK_LINE(53)
		{
			HX_STACK_LINE(53)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			Array< ::String > _g1 = ::Reflect_obj::fields(this->properties);		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(53)
			while(((_g < _g1->length))){
				HX_STACK_LINE(53)
				::String propertyName = _g1->__get(_g);		HX_STACK_VAR(propertyName,"propertyName");
				HX_STACK_LINE(53)
				++(_g);
				HX_STACK_LINE(55)
				if (((propertyName != HX_CSTRING("filter")))){
					HX_STACK_LINE(57)
					Dynamic o = this->filter;		HX_STACK_VAR(o,"o");
					HX_STACK_LINE(57)
					if (((o != null()))){
						HX_STACK_LINE(57)
						o->__SetField(propertyName,::Reflect_obj::field(this->properties,propertyName),false);
					}
				}
			}
		}
		struct _Function_1_1{
			inline static Dynamic Block( ::motion::actuators::FilterActuator_obj *__this){
				HX_STACK_PUSH("*::closure","motion/actuators/FilterActuator.hx",63);
				{
					HX_STACK_LINE(63)
					Dynamic target = __this->target;		HX_STACK_VAR(target,"target");
					HX_STACK_LINE(63)
					Dynamic value = null();		HX_STACK_VAR(value,"value");
					HX_STACK_LINE(63)
					if ((::Reflect_obj::hasField(target,HX_CSTRING("filters")))){
						HX_STACK_LINE(63)
						value = ::Reflect_obj::field(target,HX_CSTRING("filters"));
					}
					else{
						HX_STACK_LINE(63)
						value = (  (((target == null()))) ? Dynamic(null()) : Dynamic(target->__Field(HX_CSTRING("filters"),true)) );
					}
					HX_STACK_LINE(63)
					return value;
				}
				return null();
			}
		};
		HX_STACK_LINE(63)
		Array< ::Dynamic > filters = _Function_1_1::Block(this);		HX_STACK_VAR(filters,"filters");
		HX_STACK_LINE(64)
		{
			HX_STACK_LINE(64)
			::String field = this->properties->__Field(HX_CSTRING("filter"),true);		HX_STACK_VAR(field,"field");
			HX_STACK_LINE(64)
			if (((filters != null()))){
				HX_STACK_LINE(64)
				filters->__SetField(field,this->filter,false);
			}
		}
		HX_STACK_LINE(65)
		{
			HX_STACK_LINE(65)
			Dynamic target = this->target;		HX_STACK_VAR(target,"target");
			HX_STACK_LINE(65)
			if ((::Reflect_obj::hasField(target,HX_CSTRING("filters")))){
				HX_STACK_LINE(65)
				if (((target != null()))){
					HX_STACK_LINE(65)
					target->__SetField(HX_CSTRING("filters"),filters,false);
				}
			}
			else{
				HX_STACK_LINE(65)
				if (((target != null()))){
					HX_STACK_LINE(65)
					target->__SetField(HX_CSTRING("filters"),filters,true);
				}
			}
		}
	}
return null();
}



FilterActuator_obj::FilterActuator_obj()
{
}

void FilterActuator_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(FilterActuator);
	HX_MARK_MEMBER_NAME(filterIndex,"filterIndex");
	HX_MARK_MEMBER_NAME(filterClass,"filterClass");
	HX_MARK_MEMBER_NAME(filter,"filter");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void FilterActuator_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(filterIndex,"filterIndex");
	HX_VISIT_MEMBER_NAME(filterClass,"filterClass");
	HX_VISIT_MEMBER_NAME(filter,"filter");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic FilterActuator_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"apply") ) { return apply_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
		if (HX_FIELD_EQ(inName,"filter") ) { return filter; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"initialize") ) { return initialize_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"filterIndex") ) { return filterIndex; }
		if (HX_FIELD_EQ(inName,"filterClass") ) { return filterClass; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic FilterActuator_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"filter") ) { filter=inValue.Cast< ::flash::filters::BitmapFilter >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"filterIndex") ) { filterIndex=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"filterClass") ) { filterClass=inValue.Cast< ::Class >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void FilterActuator_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("filterIndex"));
	outFields->push(HX_CSTRING("filterClass"));
	outFields->push(HX_CSTRING("filter"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("update"),
	HX_CSTRING("initialize"),
	HX_CSTRING("apply"),
	HX_CSTRING("filterIndex"),
	HX_CSTRING("filterClass"),
	HX_CSTRING("filter"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(FilterActuator_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(FilterActuator_obj::__mClass,"__mClass");
};

Class FilterActuator_obj::__mClass;

void FilterActuator_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("motion.actuators.FilterActuator"), hx::TCanCast< FilterActuator_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void FilterActuator_obj::__boot()
{
}

} // end namespace motion
} // end namespace actuators
