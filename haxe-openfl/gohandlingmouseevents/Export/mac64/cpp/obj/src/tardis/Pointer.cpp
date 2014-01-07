#include <hxcpp.h>

#ifndef INCLUDED_tardis_Pointer
#include <tardis/Pointer.h>
#endif
#ifndef INCLUDED_tardis_Scheduler
#include <tardis/Scheduler.h>
#endif
namespace tardis{

Void Pointer_obj::__construct(Dynamic from)
{
HX_STACK_PUSH("Pointer::new","tardis/Go.hx",290);
{
	HX_STACK_LINE(291)
	this->heapObj = from;
	HX_STACK_LINE(292)
	this->offs = Array_obj< int >::__new();
}
;
	return null();
}

Pointer_obj::~Pointer_obj() { }

Dynamic Pointer_obj::__CreateEmpty() { return  new Pointer_obj; }
hx::ObjectPtr< Pointer_obj > Pointer_obj::__new(Dynamic from)
{  hx::ObjectPtr< Pointer_obj > result = new Pointer_obj();
	result->__construct(from);
	return result;}

Dynamic Pointer_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Pointer_obj > result = new Pointer_obj();
	result->__construct(inArgs[0]);
	return result;}

int Pointer_obj::len( ){
	HX_STACK_PUSH("Pointer::len","tardis/Go.hx",324);
	HX_STACK_THIS(this);
	HX_STACK_LINE(324)
	return this->ref()->__Field(HX_CSTRING("length"),true);
}


HX_DEFINE_DYNAMIC_FUNC0(Pointer_obj,len,return )

::tardis::Pointer Pointer_obj::addr( int off){
	HX_STACK_PUSH("Pointer::addr","tardis/Go.hx",317);
	HX_STACK_THIS(this);
	HX_STACK_ARG(off,"off");
	HX_STACK_LINE(318)
	if (((bool((off < (int)0)) || bool((off >= this->ref()->__Field(HX_CSTRING("length"),true)))))){
		HX_STACK_LINE(318)
		::tardis::Scheduler_obj::panicFromHaxe(HX_CSTRING("index out of range for valid pointer address"));
	}
	HX_STACK_LINE(319)
	::tardis::Pointer ret = ::tardis::Pointer_obj::__new(this->heapObj);		HX_STACK_VAR(ret,"ret");
	HX_STACK_LINE(320)
	ret->offs = this->offs->copy();
	HX_STACK_LINE(321)
	ret->offs[this->offs->length] = off;
	HX_STACK_LINE(322)
	return ret;
}


HX_DEFINE_DYNAMIC_FUNC1(Pointer_obj,addr,return )

Void Pointer_obj::store( Dynamic v){
{
		HX_STACK_PUSH("Pointer::store","tardis/Go.hx",306);
		HX_STACK_THIS(this);
		HX_STACK_ARG(v,"v");
		HX_STACK_LINE(307)
		if (((this->offs == null()))){
			HX_STACK_LINE(307)
			this->offs = Array_obj< int >::__new();
		}
		HX_STACK_LINE(308)
		{
			HX_STACK_LINE(308)
			::tardis::Pointer _g = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(308)
			switch( (int)(_g->offs->length)){
				case (int)0: {
					HX_STACK_LINE(309)
					this->heapObj = v;
				}
				;break;
				case (int)1: {
					HX_STACK_LINE(310)
					hx::IndexRef((this->heapObj).mPtr,this->offs->__get((int)0)) = v;
				}
				;break;
				default: {
					HX_STACK_LINE(312)
					Dynamic a = this->heapObj;		HX_STACK_VAR(a,"a");
					HX_STACK_LINE(313)
					{
						HX_STACK_LINE(313)
						int _g2 = (int)0;		HX_STACK_VAR(_g2,"_g2");
						int _g1 = (this->offs->length - (int)1);		HX_STACK_VAR(_g1,"_g1");
						HX_STACK_LINE(313)
						while(((_g2 < _g1))){
							HX_STACK_LINE(313)
							int i = (_g2)++;		HX_STACK_VAR(i,"i");
							HX_STACK_LINE(313)
							a = a->__GetItem(this->offs->__get(i));
						}
					}
					HX_STACK_LINE(314)
					hx::IndexRef((a).mPtr,this->offs->__get((this->offs->length - (int)1))) = v;
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Pointer_obj,store,(void))

Dynamic Pointer_obj::ref( ){
	HX_STACK_PUSH("Pointer::ref","tardis/Go.hx",300);
	HX_STACK_THIS(this);
	HX_STACK_LINE(301)
	Dynamic ret = this->heapObj;		HX_STACK_VAR(ret,"ret");
	HX_STACK_LINE(302)
	{
		HX_STACK_LINE(302)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		int _g = this->offs->length;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(302)
		while(((_g1 < _g))){
			HX_STACK_LINE(302)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(303)
			ret = ret->__GetItem(this->offs->__get(i));
		}
	}
	HX_STACK_LINE(304)
	return ret;
}


HX_DEFINE_DYNAMIC_FUNC0(Pointer_obj,ref,return )

Dynamic Pointer_obj::load( ){
	HX_STACK_PUSH("Pointer::load","tardis/Go.hx",294);
	HX_STACK_THIS(this);
	HX_STACK_LINE(294)
	return this->ref();
}


HX_DEFINE_DYNAMIC_FUNC0(Pointer_obj,load,return )

::tardis::Pointer Pointer_obj::copy( ::tardis::Pointer v){
	HX_STACK_PUSH("Pointer::copy","tardis/Go.hx",327);
	HX_STACK_ARG(v,"v");
	HX_STACK_LINE(328)
	::tardis::Pointer r = ::tardis::Pointer_obj::__new(v->heapObj);		HX_STACK_VAR(r,"r");
	HX_STACK_LINE(329)
	r->offs = v->offs->copy();
	HX_STACK_LINE(330)
	return r;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Pointer_obj,copy,return )


Pointer_obj::Pointer_obj()
{
}

void Pointer_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Pointer);
	HX_MARK_MEMBER_NAME(offs,"offs");
	HX_MARK_MEMBER_NAME(heapObj,"heapObj");
	HX_MARK_END_CLASS();
}

void Pointer_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(offs,"offs");
	HX_VISIT_MEMBER_NAME(heapObj,"heapObj");
}

Dynamic Pointer_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"len") ) { return len_dyn(); }
		if (HX_FIELD_EQ(inName,"ref") ) { return ref_dyn(); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"copy") ) { return copy_dyn(); }
		if (HX_FIELD_EQ(inName,"addr") ) { return addr_dyn(); }
		if (HX_FIELD_EQ(inName,"load") ) { return load_dyn(); }
		if (HX_FIELD_EQ(inName,"offs") ) { return offs; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"store") ) { return store_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"heapObj") ) { return heapObj; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Pointer_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"offs") ) { offs=inValue.Cast< Array< int > >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"heapObj") ) { heapObj=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Pointer_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("offs"));
	outFields->push(HX_CSTRING("heapObj"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("copy"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("len"),
	HX_CSTRING("addr"),
	HX_CSTRING("store"),
	HX_CSTRING("ref"),
	HX_CSTRING("load"),
	HX_CSTRING("offs"),
	HX_CSTRING("heapObj"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Pointer_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Pointer_obj::__mClass,"__mClass");
};

Class Pointer_obj::__mClass;

void Pointer_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("tardis.Pointer"), hx::TCanCast< Pointer_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Pointer_obj::__boot()
{
}

} // end namespace tardis
