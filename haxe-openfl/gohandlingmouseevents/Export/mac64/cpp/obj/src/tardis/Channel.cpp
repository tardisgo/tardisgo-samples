#include <hxcpp.h>

#ifndef INCLUDED_tardis_Channel
#include <tardis/Channel.h>
#endif
#ifndef INCLUDED_tardis_Deep
#include <tardis/Deep.h>
#endif
#ifndef INCLUDED_tardis_Scheduler
#include <tardis/Scheduler.h>
#endif
namespace tardis{

Void Channel_obj::__construct(int how_many_entries)
{
HX_STACK_PUSH("Channel::new","tardis/Go.hx",528);
{
	HX_STACK_LINE(529)
	if (((how_many_entries <= (int)0))){
		HX_STACK_LINE(530)
		how_many_entries = (int)1;
	}
	HX_STACK_LINE(531)
	this->entries = Dynamic( Array_obj<Dynamic>::__new() );
	HX_STACK_LINE(532)
	this->max_entries = how_many_entries;
	HX_STACK_LINE(533)
	this->oldest_entry = (int)0;
	HX_STACK_LINE(534)
	this->num_entries = (int)0;
	HX_STACK_LINE(535)
	this->closed = false;
}
;
	return null();
}

Channel_obj::~Channel_obj() { }

Dynamic Channel_obj::__CreateEmpty() { return  new Channel_obj; }
hx::ObjectPtr< Channel_obj > Channel_obj::__new(int how_many_entries)
{  hx::ObjectPtr< Channel_obj > result = new Channel_obj();
	result->__construct(how_many_entries);
	return result;}

Dynamic Channel_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Channel_obj > result = new Channel_obj();
	result->__construct(inArgs[0]);
	return result;}

Void Channel_obj::close( ){
{
		HX_STACK_PUSH("Channel::close","tardis/Go.hx",584);
		HX_STACK_THIS(this);
		HX_STACK_LINE(584)
		this->closed = true;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Channel_obj,close,(void))

int Channel_obj::cap( ){
	HX_STACK_PUSH("Channel::cap","tardis/Go.hx",581);
	HX_STACK_THIS(this);
	HX_STACK_LINE(581)
	return this->max_entries;
}


HX_DEFINE_DYNAMIC_FUNC0(Channel_obj,cap,return )

int Channel_obj::len( ){
	HX_STACK_PUSH("Channel::len","tardis/Go.hx",578);
	HX_STACK_THIS(this);
	HX_STACK_LINE(578)
	return this->num_entries;
}


HX_DEFINE_DYNAMIC_FUNC0(Channel_obj,len,return )

Dynamic Channel_obj::receive( Dynamic zero){
	HX_STACK_PUSH("Channel::receive","tardis/Go.hx",563);
	HX_STACK_THIS(this);
	HX_STACK_ARG(zero,"zero");
	HX_STACK_LINE(564)
	Dynamic ret = zero;		HX_STACK_VAR(ret,"ret");
	HX_STACK_LINE(565)
	if (((this->num_entries > (int)0))){
		HX_STACK_LINE(566)
		ret = this->entries->__GetItem(this->oldest_entry);
		HX_STACK_LINE(567)
		this->oldest_entry = hx::Mod(((this->oldest_entry + (int)1)),this->max_entries);
		HX_STACK_LINE(568)
		(this->num_entries)--;
		struct _Function_2_1{
			inline static Dynamic Block( Dynamic &ret){
				HX_STACK_PUSH("*::closure","tardis/Go.hx",569);
				{
					hx::Anon __result = hx::Anon_obj::Create();
					__result->Add(HX_CSTRING("r0") , ret,false);
					__result->Add(HX_CSTRING("r1") , true,false);
					return __result;
				}
				return null();
			}
		};
		HX_STACK_LINE(569)
		return _Function_2_1::Block(ret);
	}
	else{
		HX_STACK_LINE(571)
		if ((this->closed)){
			struct _Function_3_1{
				inline static Dynamic Block( Dynamic &ret){
					HX_STACK_PUSH("*::closure","tardis/Go.hx",572);
					{
						hx::Anon __result = hx::Anon_obj::Create();
						__result->Add(HX_CSTRING("r0") , ret,false);
						__result->Add(HX_CSTRING("r1") , false,false);
						return __result;
					}
					return null();
				}
			};
			HX_STACK_LINE(572)
			return _Function_3_1::Block(ret);
		}
		else{
			HX_STACK_LINE(574)
			::tardis::Scheduler_obj::panicFromHaxe(HX_CSTRING("channel receive unreachable code!"));
			struct _Function_3_1{
				inline static Dynamic Block( Dynamic &ret){
					HX_STACK_PUSH("*::closure","tardis/Go.hx",575);
					{
						hx::Anon __result = hx::Anon_obj::Create();
						__result->Add(HX_CSTRING("r0") , ret,false);
						__result->Add(HX_CSTRING("r1") , false,false);
						return __result;
					}
					return null();
				}
			};
			HX_STACK_LINE(575)
			return _Function_3_1::Block(ret);
		}
	}
	HX_STACK_LINE(565)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Channel_obj,receive,return )

bool Channel_obj::hasContents( ){
	HX_STACK_PUSH("Channel::hasContents","tardis/Go.hx",558);
	HX_STACK_THIS(this);
	HX_STACK_LINE(560)
	if ((this->closed)){
		HX_STACK_LINE(560)
		return true;
	}
	HX_STACK_LINE(561)
	return (this->num_entries != (int)0);
}


HX_DEFINE_DYNAMIC_FUNC0(Channel_obj,hasContents,return )

bool Channel_obj::hasNoContents( ){
	HX_STACK_PUSH("Channel::hasNoContents","tardis/Go.hx",553);
	HX_STACK_THIS(this);
	HX_STACK_LINE(553)
	if ((this->closed)){
		HX_STACK_LINE(555)
		return false;
	}
	else{
		HX_STACK_LINE(556)
		return (this->num_entries == (int)0);
	}
	HX_STACK_LINE(553)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC0(Channel_obj,hasNoContents,return )

bool Channel_obj::send( Dynamic source){
	HX_STACK_PUSH("Channel::send","tardis/Go.hx",542);
	HX_STACK_THIS(this);
	HX_STACK_ARG(source,"source");
	HX_STACK_LINE(543)
	if ((this->closed)){
		HX_STACK_LINE(543)
		::tardis::Scheduler_obj::panicFromHaxe(HX_CSTRING("attempt to send to closed channel"));
	}
	HX_STACK_LINE(544)
	int next_element;		HX_STACK_VAR(next_element,"next_element");
	HX_STACK_LINE(545)
	if ((this->hasSpace())){
		HX_STACK_LINE(546)
		next_element = hx::Mod(((this->oldest_entry + this->num_entries)),this->max_entries);
		HX_STACK_LINE(547)
		(this->num_entries)++;
		HX_STACK_LINE(548)
		hx::IndexRef((this->entries).mPtr,next_element) = ::tardis::Deep_obj::copy(source);
		HX_STACK_LINE(549)
		return true;
	}
	else{
		HX_STACK_LINE(551)
		return false;
	}
	HX_STACK_LINE(545)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC1(Channel_obj,send,return )

bool Channel_obj::hasSpace( ){
	HX_STACK_PUSH("Channel::hasSpace","tardis/Go.hx",537);
	HX_STACK_THIS(this);
	HX_STACK_LINE(539)
	if ((this->closed)){
		HX_STACK_LINE(539)
		return false;
	}
	HX_STACK_LINE(540)
	return (this->num_entries < this->max_entries);
}


HX_DEFINE_DYNAMIC_FUNC0(Channel_obj,hasSpace,return )


Channel_obj::Channel_obj()
{
}

void Channel_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Channel);
	HX_MARK_MEMBER_NAME(closed,"closed");
	HX_MARK_MEMBER_NAME(oldest_entry,"oldest_entry");
	HX_MARK_MEMBER_NAME(num_entries,"num_entries");
	HX_MARK_MEMBER_NAME(max_entries,"max_entries");
	HX_MARK_MEMBER_NAME(entries,"entries");
	HX_MARK_END_CLASS();
}

void Channel_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(closed,"closed");
	HX_VISIT_MEMBER_NAME(oldest_entry,"oldest_entry");
	HX_VISIT_MEMBER_NAME(num_entries,"num_entries");
	HX_VISIT_MEMBER_NAME(max_entries,"max_entries");
	HX_VISIT_MEMBER_NAME(entries,"entries");
}

Dynamic Channel_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"cap") ) { return cap_dyn(); }
		if (HX_FIELD_EQ(inName,"len") ) { return len_dyn(); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"send") ) { return send_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"close") ) { return close_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"closed") ) { return closed; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"receive") ) { return receive_dyn(); }
		if (HX_FIELD_EQ(inName,"entries") ) { return entries; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"hasSpace") ) { return hasSpace_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"hasContents") ) { return hasContents_dyn(); }
		if (HX_FIELD_EQ(inName,"num_entries") ) { return num_entries; }
		if (HX_FIELD_EQ(inName,"max_entries") ) { return max_entries; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"oldest_entry") ) { return oldest_entry; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"hasNoContents") ) { return hasNoContents_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Channel_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"closed") ) { closed=inValue.Cast< bool >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"entries") ) { entries=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"num_entries") ) { num_entries=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"max_entries") ) { max_entries=inValue.Cast< int >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"oldest_entry") ) { oldest_entry=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Channel_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("closed"));
	outFields->push(HX_CSTRING("oldest_entry"));
	outFields->push(HX_CSTRING("num_entries"));
	outFields->push(HX_CSTRING("max_entries"));
	outFields->push(HX_CSTRING("entries"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("close"),
	HX_CSTRING("cap"),
	HX_CSTRING("len"),
	HX_CSTRING("receive"),
	HX_CSTRING("hasContents"),
	HX_CSTRING("hasNoContents"),
	HX_CSTRING("send"),
	HX_CSTRING("hasSpace"),
	HX_CSTRING("closed"),
	HX_CSTRING("oldest_entry"),
	HX_CSTRING("num_entries"),
	HX_CSTRING("max_entries"),
	HX_CSTRING("entries"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Channel_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Channel_obj::__mClass,"__mClass");
};

Class Channel_obj::__mClass;

void Channel_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("tardis.Channel"), hx::TCanCast< Channel_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Channel_obj::__boot()
{
}

} // end namespace tardis
