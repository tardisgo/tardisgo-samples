#include <hxcpp.h>

#ifndef INCLUDED_flash__Vector_Vector_Impl_
#include <flash/_Vector/Vector_Impl_.h>
#endif
namespace flash{
namespace _Vector{

Void Vector_Impl__obj::__construct()
{
	return null();
}

Vector_Impl__obj::~Vector_Impl__obj() { }

Dynamic Vector_Impl__obj::__CreateEmpty() { return  new Vector_Impl__obj; }
hx::ObjectPtr< Vector_Impl__obj > Vector_Impl__obj::__new()
{  hx::ObjectPtr< Vector_Impl__obj > result = new Vector_Impl__obj();
	result->__construct();
	return result;}

Dynamic Vector_Impl__obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Vector_Impl__obj > result = new Vector_Impl__obj();
	result->__construct();
	return result;}

Dynamic Vector_Impl__obj::_new( Dynamic length,Dynamic fixed){
	HX_STACK_PUSH("Vector_Impl_::_new","flash/Vector.hx",13);
	HX_STACK_ARG(length,"length");
	HX_STACK_ARG(fixed,"fixed");
	HX_STACK_LINE(13)
	return Dynamic( Array_obj<Dynamic>::__new() );
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Vector_Impl__obj,_new,return )

Dynamic Vector_Impl__obj::concat( Dynamic this1,Dynamic a){
	HX_STACK_PUSH("Vector_Impl_::concat","flash/Vector.hx",18);
	HX_STACK_ARG(this1,"this1");
	HX_STACK_ARG(a,"a");
	HX_STACK_LINE(18)
	return this1->__Field(HX_CSTRING("concat"),true)(a);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Vector_Impl__obj,concat,return )

Dynamic Vector_Impl__obj::copy( Dynamic this1){
	HX_STACK_PUSH("Vector_Impl_::copy","flash/Vector.hx",25);
	HX_STACK_ARG(this1,"this1");
	HX_STACK_LINE(25)
	return this1->__Field(HX_CSTRING("copy"),true)();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Vector_Impl__obj,copy,return )

Dynamic Vector_Impl__obj::iterator( Dynamic this1){
	HX_STACK_PUSH("Vector_Impl_::iterator","flash/Vector.hx",32);
	HX_STACK_ARG(this1,"this1");
	HX_STACK_LINE(32)
	return this1->__Field(HX_CSTRING("iterator"),true)();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Vector_Impl__obj,iterator,return )

::String Vector_Impl__obj::join( Dynamic this1,::String sep){
	HX_STACK_PUSH("Vector_Impl_::join","flash/Vector.hx",39);
	HX_STACK_ARG(this1,"this1");
	HX_STACK_ARG(sep,"sep");
	HX_STACK_LINE(39)
	return this1->__Field(HX_CSTRING("join"),true)(sep);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Vector_Impl__obj,join,return )

Dynamic Vector_Impl__obj::pop( Dynamic this1){
	HX_STACK_PUSH("Vector_Impl_::pop","flash/Vector.hx",46);
	HX_STACK_ARG(this1,"this1");
	HX_STACK_LINE(46)
	return this1->__Field(HX_CSTRING("pop"),true)();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Vector_Impl__obj,pop,return )

int Vector_Impl__obj::push( Dynamic this1,Dynamic x){
	HX_STACK_PUSH("Vector_Impl_::push","flash/Vector.hx",53);
	HX_STACK_ARG(this1,"this1");
	HX_STACK_ARG(x,"x");
	HX_STACK_LINE(53)
	return this1->__Field(HX_CSTRING("push"),true)(x);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Vector_Impl__obj,push,return )

Void Vector_Impl__obj::reverse( Dynamic this1){
{
		HX_STACK_PUSH("Vector_Impl_::reverse","flash/Vector.hx",60);
		HX_STACK_ARG(this1,"this1");
		HX_STACK_LINE(60)
		this1->__Field(HX_CSTRING("reverse"),true)();
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Vector_Impl__obj,reverse,(void))

Dynamic Vector_Impl__obj::shift( Dynamic this1){
	HX_STACK_PUSH("Vector_Impl_::shift","flash/Vector.hx",67);
	HX_STACK_ARG(this1,"this1");
	HX_STACK_LINE(67)
	return this1->__Field(HX_CSTRING("shift"),true)();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Vector_Impl__obj,shift,return )

Void Vector_Impl__obj::unshift( Dynamic this1,Dynamic x){
{
		HX_STACK_PUSH("Vector_Impl_::unshift","flash/Vector.hx",74);
		HX_STACK_ARG(this1,"this1");
		HX_STACK_ARG(x,"x");
		HX_STACK_LINE(74)
		this1->__Field(HX_CSTRING("unshift"),true)(x);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Vector_Impl__obj,unshift,(void))

Dynamic Vector_Impl__obj::slice( Dynamic this1,Dynamic pos,Dynamic end){
	HX_STACK_PUSH("Vector_Impl_::slice","flash/Vector.hx",81);
	HX_STACK_ARG(this1,"this1");
	HX_STACK_ARG(pos,"pos");
	HX_STACK_ARG(end,"end");
	HX_STACK_LINE(81)
	return this1->__Field(HX_CSTRING("slice"),true)(pos,end);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Vector_Impl__obj,slice,return )

Void Vector_Impl__obj::sort( Dynamic this1,Dynamic f){
{
		HX_STACK_PUSH("Vector_Impl_::sort","flash/Vector.hx",88);
		HX_STACK_ARG(this1,"this1");
		HX_STACK_ARG(f,"f");
		HX_STACK_LINE(88)
		this1->__Field(HX_CSTRING("sort"),true)(f);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Vector_Impl__obj,sort,(void))

Dynamic Vector_Impl__obj::splice( Dynamic this1,int pos,int len){
	HX_STACK_PUSH("Vector_Impl_::splice","flash/Vector.hx",95);
	HX_STACK_ARG(this1,"this1");
	HX_STACK_ARG(pos,"pos");
	HX_STACK_ARG(len,"len");
	HX_STACK_LINE(95)
	return this1->__Field(HX_CSTRING("splice"),true)(pos,len);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Vector_Impl__obj,splice,return )

::String Vector_Impl__obj::toString( Dynamic this1){
	HX_STACK_PUSH("Vector_Impl_::toString","flash/Vector.hx",102);
	HX_STACK_ARG(this1,"this1");
	HX_STACK_LINE(102)
	return this1->toString();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Vector_Impl__obj,toString,return )

int Vector_Impl__obj::indexOf( Dynamic this1,Dynamic x,Dynamic __o_from){
Dynamic from = __o_from.Default(0);
	HX_STACK_PUSH("Vector_Impl_::indexOf","flash/Vector.hx",109);
	HX_STACK_ARG(this1,"this1");
	HX_STACK_ARG(x,"x");
	HX_STACK_ARG(from,"from");
{
		HX_STACK_LINE(111)
		{
			HX_STACK_LINE(111)
			int _g1 = from;		HX_STACK_VAR(_g1,"_g1");
			int _g = this1->__Field(HX_CSTRING("length"),true);		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(111)
			while(((_g1 < _g))){
				HX_STACK_LINE(111)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(113)
				if (((this1->__GetItem(i) == x))){
					HX_STACK_LINE(113)
					return i;
				}
			}
		}
		HX_STACK_LINE(121)
		return (int)-1;
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Vector_Impl__obj,indexOf,return )

int Vector_Impl__obj::lastIndexOf( Dynamic this1,Dynamic x,Dynamic __o_from){
Dynamic from = __o_from.Default(0);
	HX_STACK_PUSH("Vector_Impl_::lastIndexOf","flash/Vector.hx",126);
	HX_STACK_ARG(this1,"this1");
	HX_STACK_ARG(x,"x");
	HX_STACK_ARG(from,"from");
{
		HX_STACK_LINE(128)
		int i = (this1->__Field(HX_CSTRING("length"),true) - (int)1);		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(130)
		while(((i >= from))){
			HX_STACK_LINE(132)
			if (((this1->__GetItem(i) == x))){
				HX_STACK_LINE(132)
				return i;
			}
			HX_STACK_LINE(133)
			(i)--;
		}
		HX_STACK_LINE(137)
		return (int)-1;
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Vector_Impl__obj,lastIndexOf,return )

Dynamic Vector_Impl__obj::ofArray( Dynamic a){
	HX_STACK_PUSH("Vector_Impl_::ofArray","flash/Vector.hx",142);
	HX_STACK_ARG(a,"a");
	HX_STACK_LINE(142)
	return ::flash::_Vector::Vector_Impl__obj::concat(::flash::_Vector::Vector_Impl__obj::_new(null(),null()),a);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Vector_Impl__obj,ofArray,return )

Dynamic Vector_Impl__obj::convert( Dynamic v){
	HX_STACK_PUSH("Vector_Impl_::convert","flash/Vector.hx",149);
	HX_STACK_ARG(v,"v");
	HX_STACK_LINE(149)
	return v;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Vector_Impl__obj,convert,return )

Dynamic Vector_Impl__obj::fromArray( Dynamic a){
	HX_STACK_PUSH("Vector_Impl_::fromArray","flash/Vector.hx",156);
	HX_STACK_ARG(a,"a");
	HX_STACK_LINE(156)
	return a;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Vector_Impl__obj,fromArray,return )

Dynamic Vector_Impl__obj::toArray( Dynamic this1){
	HX_STACK_PUSH("Vector_Impl_::toArray","flash/Vector.hx",163);
	HX_STACK_ARG(this1,"this1");
	HX_STACK_LINE(163)
	return this1;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Vector_Impl__obj,toArray,return )

int Vector_Impl__obj::get_length( Dynamic this1){
	HX_STACK_PUSH("Vector_Impl_::get_length","flash/Vector.hx",177);
	HX_STACK_ARG(this1,"this1");
	HX_STACK_LINE(177)
	return this1->__Field(HX_CSTRING("length"),true);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Vector_Impl__obj,get_length,return )

int Vector_Impl__obj::set_length( Dynamic this1,int value){
	HX_STACK_PUSH("Vector_Impl_::set_length","flash/Vector.hx",184);
	HX_STACK_ARG(this1,"this1");
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(184)
	return value;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Vector_Impl__obj,set_length,return )

bool Vector_Impl__obj::get_fixed( Dynamic this1){
	HX_STACK_PUSH("Vector_Impl_::get_fixed","flash/Vector.hx",191);
	HX_STACK_ARG(this1,"this1");
	HX_STACK_LINE(191)
	return false;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Vector_Impl__obj,get_fixed,return )

bool Vector_Impl__obj::set_fixed( Dynamic this1,bool value){
	HX_STACK_PUSH("Vector_Impl_::set_fixed","flash/Vector.hx",198);
	HX_STACK_ARG(this1,"this1");
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(198)
	return value;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Vector_Impl__obj,set_fixed,return )


Vector_Impl__obj::Vector_Impl__obj()
{
}

void Vector_Impl__obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Vector_Impl_);
	HX_MARK_END_CLASS();
}

void Vector_Impl__obj::__Visit(HX_VISIT_PARAMS)
{
}

Dynamic Vector_Impl__obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"pop") ) { return pop_dyn(); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"_new") ) { return _new_dyn(); }
		if (HX_FIELD_EQ(inName,"copy") ) { return copy_dyn(); }
		if (HX_FIELD_EQ(inName,"join") ) { return join_dyn(); }
		if (HX_FIELD_EQ(inName,"push") ) { return push_dyn(); }
		if (HX_FIELD_EQ(inName,"sort") ) { return sort_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"shift") ) { return shift_dyn(); }
		if (HX_FIELD_EQ(inName,"slice") ) { return slice_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"concat") ) { return concat_dyn(); }
		if (HX_FIELD_EQ(inName,"splice") ) { return splice_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"reverse") ) { return reverse_dyn(); }
		if (HX_FIELD_EQ(inName,"unshift") ) { return unshift_dyn(); }
		if (HX_FIELD_EQ(inName,"indexOf") ) { return indexOf_dyn(); }
		if (HX_FIELD_EQ(inName,"ofArray") ) { return ofArray_dyn(); }
		if (HX_FIELD_EQ(inName,"convert") ) { return convert_dyn(); }
		if (HX_FIELD_EQ(inName,"toArray") ) { return toArray_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"iterator") ) { return iterator_dyn(); }
		if (HX_FIELD_EQ(inName,"toString") ) { return toString_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"fromArray") ) { return fromArray_dyn(); }
		if (HX_FIELD_EQ(inName,"get_fixed") ) { return get_fixed_dyn(); }
		if (HX_FIELD_EQ(inName,"set_fixed") ) { return set_fixed_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"get_length") ) { return get_length_dyn(); }
		if (HX_FIELD_EQ(inName,"set_length") ) { return set_length_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"lastIndexOf") ) { return lastIndexOf_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Vector_Impl__obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void Vector_Impl__obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("_new"),
	HX_CSTRING("concat"),
	HX_CSTRING("copy"),
	HX_CSTRING("iterator"),
	HX_CSTRING("join"),
	HX_CSTRING("pop"),
	HX_CSTRING("push"),
	HX_CSTRING("reverse"),
	HX_CSTRING("shift"),
	HX_CSTRING("unshift"),
	HX_CSTRING("slice"),
	HX_CSTRING("sort"),
	HX_CSTRING("splice"),
	HX_CSTRING("toString"),
	HX_CSTRING("indexOf"),
	HX_CSTRING("lastIndexOf"),
	HX_CSTRING("ofArray"),
	HX_CSTRING("convert"),
	HX_CSTRING("fromArray"),
	HX_CSTRING("toArray"),
	HX_CSTRING("get_length"),
	HX_CSTRING("set_length"),
	HX_CSTRING("get_fixed"),
	HX_CSTRING("set_fixed"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Vector_Impl__obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Vector_Impl__obj::__mClass,"__mClass");
};

Class Vector_Impl__obj::__mClass;

void Vector_Impl__obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("flash._Vector.Vector_Impl_"), hx::TCanCast< Vector_Impl__obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Vector_Impl__obj::__boot()
{
}

} // end namespace flash
} // end namespace _Vector
