/**
 * \file Fish.cpp
 *
 * \author Justin Vesche
 */

#include "pch.h"
#include <string>
#include "Fish.h"
#include "Aquarium.h"

using namespace Gdiplus;
using namespace std;


/// ammount of pixels when the fish should reverse
const double encounter = 10.0;

/**
 * Constructor
 * \param aquarium The aquarium we are in
 * \param filename Filename for the image we use
 */
CFish::CFish(CAquarium* aquarium, const std::wstring& filename) :
    CItem(aquarium, filename)
{
}

/**
 * Handle updates in time of our fish
 *
 * This is called before we draw and allows us to
 * move our fish. We add our speed times the amount
 * of time that has elapsed.
 * \param elapsed Time elapsed since the class call
 */
void CFish::Update(double elapsed)
{
    SetLocation(GetX() + mSpeedX * elapsed,
        GetY() + mSpeedY * elapsed);

    
    
    if (mSpeedX > 0 && GetX() >= (-GetWidth() / 2) - encounter + GetAquarium()->GetWidth())
    {
        mSpeedX = -mSpeedX;
        SetMirror(mSpeedX < 0);
    }
    else if (mSpeedX < 0 && GetX() <= GetWidth() / 2 + encounter)
    {
        mSpeedX = -mSpeedX;
        SetMirror(mSpeedX < 0);
    }

    if (mSpeedY > 0 && GetY() >= (-GetHeight() / 2) - encounter + GetAquarium()->GetHeight())
    {
        mSpeedY = -mSpeedY;
    }
    else if (mSpeedY < 0 && GetY() <= encounter + GetHeight() / 2)
    {
        mSpeedY = -mSpeedY;
    }
}



/**
 * Save this item to an XML node
 * \param node The node we are going to be a child of
 * \return a shared_ptr of an XmlNode
 */
std::shared_ptr<xmlnode::CXmlNode>
CFish::XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node)
{
    auto itemNode = CItem::XmlSave(node);

    itemNode->SetAttribute(L"speedx", mSpeedX);
    itemNode->SetAttribute(L"speedy", mSpeedY);

    return itemNode;
}


/**
 * Load the attributes for an fish node.
 *
 * This is the Fish verision of load.
 *
 * \param node The Xml node we are loading the item from
 */
void CFish::XmlLoad(const std::shared_ptr<xmlnode::CXmlNode>& node)
{
    CItem::XmlLoad(node);
    mSpeedX = node->GetAttributeDoubleValue(L"speedx", 0);
    mSpeedY = node->GetAttributeDoubleValue(L"speedy", 0);

    SetMirror(mSpeedX < 0);
}
