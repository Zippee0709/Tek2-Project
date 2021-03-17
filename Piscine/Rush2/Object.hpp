/*
** EPITECH PROJECT, 2019
** Object.hpp
** File description:
** Object include
*/

#ifndef OBJECT
#define OBJECT
#include <iostream>

class Object {
	public:
		typedef enum Type {
			ORIGIN,
			PONY,
			TED,
			BOXES,
			GIFTPAPERS
		} TYPE;
		Object();
		std::string getTitle() const { return this->_title ;};
		Object *getObject() const {return this->_obj;};
		TYPE getType() const { return this->_type;};
		void setObject(Object *obj);
		virtual ~Object();
	protected:
		TYPE _type = ORIGIN;
		Object(std::string const &title, Type type) : _type(type), _title(title) { };
		Object(Type type) : _type(type) { };
		std::string _title = "";
		Object *_obj = NULL;
	private:
};

Object **MyUnitTests();

#endif