/**
 * \file Fish.h
 *
 * \author Justin Vesche
 *
 * Class that creates a Fish
 *
 * This class creates a foundation that can describe
 * a fish that we add to the aquarium.
 */


#pragma once
#include "Item.h"

class CAquarium;
/**
 * Base class for a fish
 * This applies to all of the fish, but not the decor
 * items in the aquarium.
 */
class CFish : public CItem
{
public:
    /// Default constructor (disabled)
    CFish() = delete;

    /// Copy constructor (disabled)
    CFish(const CFish&) = delete;

    void Update(double elapsed);

    virtual std::shared_ptr<xmlnode::CXmlNode>
        XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node);

    virtual void XmlLoad(const std::shared_ptr<xmlnode::CXmlNode>& node);
    
    /**
    * Set the X speed of fish
    * \param speedX the speed to be set
    */
    void setSpeedX(double speedX) { mSpeedX = speedX; }

    /**
     * Set the Y speed of fish
     * \param speedY the speed to be set
     */
    void setSpeedY(double speedY) { mSpeedY = speedY; }

protected:
    CFish(CAquarium* aquarium, const std::wstring& filename);

private:
    /// Fish speed in the X direction
    double mSpeedX;

    /// Fish speed in the Y direction
    double mSpeedY;
};

