/**
 * \file FishBeta.cpp
 *
 * \author Justin Vesche
 */


#include "pch.h"
#include <string>
#include "FishBeta.h"

using namespace Gdiplus;
using namespace std;


/// Maximum speed in the X direction in
/// in pixels per second
const double MaxSpeedX = 40;

/// Min speed in the X direction in
/// in pixels per second
const double MinSpeedX = 20;

/// Maximum speed in the Y direction in
/// in pixels per second
const double MaxSpeedY = 25;

/// Min speed in the Y direction in
/// in pixels per second
const double MinSpeedY = 20;

 /// Fish filename 
const wstring FishBetaImageName = L"images/beta.png";

/**
* Constructor
* \param aquarium Aquarium this fish is a member of
*/
CFishBeta::CFishBeta(CAquarium* aquarium) :
    CFish(aquarium, FishBetaImageName)
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
CFishBeta::XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node)
{
    auto itemNode = CFish::XmlSave(node);
    
    itemNode->SetAttribute(L"type", L"beta");

    return itemNode;
}

