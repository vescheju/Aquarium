/**
 * \file DecorCastle.h
 *
 * \author Justin Vesche
 *
 * Class that implements a Castle
 */

#pragma once

#include<memory>
#include "Item.h"

 /**
  * Implements a Castle
  */
class CDecorCastle : public CItem
{
public:
    CDecorCastle(CAquarium* aquarium);

    /// Default constructor (disabled)
    CDecorCastle() = delete;

    /// Copy constructor (disabled)
    CDecorCastle(const CDecorCastle&) = delete;

    virtual std::shared_ptr<xmlnode::CXmlNode>
        XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node) override;


};

