/**
 * \file FishAngler.h
 *
 * \author Justin Vesche
 *
 * Class that implements a Angler fish
 */

#pragma once

#include<memory>
#include "Item.h"
#include "Fish.h"

 /**
  * Implements a Angler fish
  */
class CFishAngler : public CFish
{
public:
    CFishAngler(CAquarium* aquarium);


    /// Default constructor (disabled)
    CFishAngler() = delete;

    /// Copy constructor (disabled)
    CFishAngler(const CFishAngler&) = delete;

    
    void SetCaught(std::shared_ptr<CItem> fish);

    virtual void SetLocation(double x, double y);

    virtual std::shared_ptr<xmlnode::CXmlNode>
        XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node) override;

private:
    
    /// Caught fish
    std::weak_ptr<CItem> mCaughtFish;
};

