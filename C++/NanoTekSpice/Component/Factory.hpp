/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Factory
*/

#ifndef COMPONENTFACTORY_HPP_
#define COMPONENTFACTORY_HPP_

#include <iostream>
#include <memory>
#include "Component.hpp"
#include "OrGate.hpp"
#include "Input.hpp"
#include "Output.hpp"
#include "Clock.hpp"
#include "True.hpp"
#include "False.hpp"
#include "NorGate.hpp"
#include "AndGate.hpp"
#include "NandGate.hpp"
#include "Gate4030.hpp"
#include "Gate4069.hpp"
#include "FourBitAdder.hpp"
#include "../Parsing/Parsing.hpp"

namespace nts {
	class ComponentFactory {
		public:
			ComponentFactory();
			~ComponentFactory() = default;
			std::unique_ptr<Component> createComponent(Parser::Type componentType, const std::string &name);

		private:
			typedef std::unique_ptr<nts::Component> (nts::ComponentFactory::*componentConstructor)(const std::string &name) const;
			std::map<Parser::Type, componentConstructor> _componentPointerFunction;
			std::unique_ptr<nts::Component> createOrGate(const std::string &name) const;
			std::unique_ptr<nts::Component> createInput(const std::string &name) const;
			std::unique_ptr<nts::Component> createOutput(const std::string &name) const;
			std::unique_ptr<nts::Component> createTrue(const std::string &name) const;
			std::unique_ptr<nts::Component> createFalse(const std::string &name) const;
			std::unique_ptr<nts::Component> createClock(const std::string &name) const;
			std::unique_ptr<nts::Component> createNorGate(const std::string &name) const;
			std::unique_ptr<nts::Component> create4030(const std::string &name) const;
			std::unique_ptr<nts::Component> create4069(const std::string &name) const;
			std::unique_ptr<nts::Component> createAndGate(const std::string &name) const;
			std::unique_ptr<nts::Component> createNandGate(const std::string &name) const;
			std::unique_ptr<nts::Component> createFourBitAdderGate(const std::string &name) const;
	};
}

#endif