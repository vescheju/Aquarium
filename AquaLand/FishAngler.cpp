/**
 * \file FishAngler.cpp
 *
 * \author Justin Vesche
 */


#include "pch.h"
#include <string>
#include "FishAngler.h"
#include "Aquarium.h"

using namespace Gdiplus;
using namespace std;


/// Maximum speed in the X direction in
/// in pixels per second
const double MaxSpeedX = 30;

/// Min speed in the X direction in
/// in pixels per second
const double MinSpeedX = 25;

/// Maximum speed in the Y direction in
/// in pixels per second
const double MaxSpeedY = 20;

/// Min speed in the Y direction in
/// in pixels per second
const double MinSpeedY = 15;

/// Fish filename 
const wstring FishAnglerImageName = L"images/angler.png";

/**
* Constructor
* \param aquarium Aquarium this fish is a member of
*/
CFishAngler::CFishAngler(CAquarium* aquarium) :
    CFish(aquarium, FishAnglerImageName)
{
    setSpeedX((MinSpeedX + ((double)rand() / RAND_MAX) * (MaxSpeedX - MinSpeedX)));
    setSpeedY((MinSpeedY + ((double)rand() / RAND_MAX) * (MaxSpeedY - MinSpeedY)));
}


/**
 * sets mCaughtFish
 * \param fish Takes a fish and sets it as mCaughtFish
 */
void CFishAngler::SetCaught(shared_ptr<CItem> fish)
{
    mCaughtFish = fish;
}

/**
 * Over rides set location from item and adds needed adjustments
 * \param x X location
 * \param y Y location
 */
void CFishAngler::SetLocation(double x, double y)
{
    // get the change of x
   double moveX = GetX() - x;
   double moveY = GetY() - y;
   // set anglers location
   CItem::SetLocation(x, y);
   // now if there is a caught fish change that location
   auto caughtTest = mCaughtFish.lock();
   // Check if there is already something caught or not
   if (caughtTest == nullptr)
   {
       // if nothing caught check if there is a collision
       if (GetAquarium()->Collision(this) != nullptr)
       {
           mCaughtFish = GetAquarium()->Collision(this);
           std::shared_ptr<CItem> caught = mCaughtFish.lock();
           double fishX = caught->GetX();
           double fishY = caught->GetY();
           caught->CItem::SetLocation(fishX - moveX, fishY - moveY);

       }
   }
   else
   {
       // if there is something caught see if there is a closer fish
       auto newFish = GetAquarium()->Collision(this);
       
       if (newFish != nullptr && newFish != caughtTest)
       {
           mCaughtFish = GetAquarium()->Collision(this);
           std::shared_ptr<CItem> caught = mCaughtFish.lock();
           double fishX = caught->GetX();
           double fishY = caught->GetY();
           caught->CItem::SetLocation(fishX - moveX, fishY - moveY);


       }
       else
       {
           std::shared_ptr<CItem> caught = mCaughtFish.lock();
           double fishX = caught->GetX();
           double fishY = caught->GetY();
           caught->CItem::SetLocation(fishX - moveX, fishY - moveY);
       }

   }
   
}

/**
 * Save this item to an XML node
 * 
 * \param node The node we are going to be a child of
 * \return itemNode a shared_ptr of an XmlNode
 */
std::shared_ptr<xmlnode::CXmlNode>
CFishAngler::XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node)
{
    auto itemNode = CFish::XmlSave(node);

    itemNode->SetAttribute(L"type", L"angler");

    return itemNode;
}
