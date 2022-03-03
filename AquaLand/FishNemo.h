/**
 * \file FishNemo.h
 *
 * \author Justin Vesche
 *
 * Class that implements a Nemo fish
 */

#pragma once
#include<memory>
#include "Item.h"
#include "Fish.h"

 /**
   * Implements a Nemo Fish
   */
class CFishNemo : public CFish
{
public:
    CFishNemo(CAquarium* aquarium);

    /// Default constructor (disabled)
    CFishNemo() = delete;

    /// Copy constructor (disabled)
    CFishNemo(const CFishNemo&) = delete;

    virtual std::shared_ptr<xmlnode::CXmlNode>
        XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node) override;

};

