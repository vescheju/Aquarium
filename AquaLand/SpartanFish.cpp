/**
 * \file SpartanFish.cpp
 *
 * \author Justin Vesche
 */


#include "pch.h"
#include <string>
#include "SpartanFish.h"

using namespace Gdiplus;
using namespace std;

/// Maximum speed in the X direction in
/// in pixels per second
const double MaxSpeedX = 140;

/// Min speed in the X direction in
/// in pixels per second
const double MinSpeedX = 90;

/// Maximum speed in the Y direction in
/// in pixels per second
const double MaxSpeedY = 110;

/// Min speed in the Y direction in
/// in pixels per second
const double MinSpeedY = 85;

/// Fish filename 
const wstring FishSpartanImageName = L"images/sparty-fish.png";

/**
* Constructor
* \param aquarium Aquarium this fish is a member of
*/
CSpartanFish::CSpartanFish(CAquarium* aquarium) :
    CFish(aquarium, FishSpartanImageName)
{
    setSpeedX((MinSpeedX + ((double)rand() / RAND_MAX) * (MaxSpeedX - MinSpeedX)));
    setSpeedY((MinSpeedY + ((double)rand() / RAND_MAX) * (MaxSpeedY - MinSpeedY)));
}

/**
 * Save this item to an XML node
 * \param node The node we are going to be a child of
 * \return itemNode a shared_ptr of an XmlNode
 */
std::shared_ptr<xmlnode::CXmlNode>
CSpartanFish::XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node)
{
    auto itemNode = CFish::XmlSave(node);

    itemNode->SetAttribute(L"type", L"sparty");

    return itemNode;
}


