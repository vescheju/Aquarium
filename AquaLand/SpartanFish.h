/**
 * \file SpartanFish.h
 *
 * \author Justin Vesche
 *
 * Class the implements a Spartan fish
 */

#pragma once

#include<memory>
#include "Item.h"
#include "Fish.h"

 /**
  * Implements a Spartan Fish
  */
class CSpartanFish : public CFish
{
public:
    CSpartanFish(CAquarium* aquarium);

    /// Default constructor (disabled)
    CSpartanFish() = delete;

    /// Copy constructor (disabled)
    CSpartanFish(const CSpartanFish&) = delete;

    virtual std::shared_ptr<xmlnode::CXmlNode>
        XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node) override;

};


