#include <iostream>
#include "Interp4Set.hh"
#include "MobileObj.hh"

using std::cout;
using std::endl;


extern "C" {
 Interp4Command* CreateCmd(void);
  const char* GetCmdName() { return "Set"; }
}




/*!
 * \brief
 *
 *
 */
Interp4Command* CreateCmd(void)
{
  return Interp4Set::CreateCmd();
}


/*!
 *
 */
Interp4Set::Interp4Set(): _Wsp_x(0), _Wsp_y(0), _Kat_Ox(0),_Kat_Oy(0)
{}


/*!
 *
 */
void Interp4Set::PrintCmd() const
{
  /*
   *  Tu trzeba napisać odpowiednio zmodyfikować kod poniżej.
   */
	cout << GetCmdName()<<" " << _Wsp_x<< " " << _Wsp_y << " "  << _Kat_Ox << " "  << _Kat_Oy << " "  << endl;
}


/*!
 *
 */
const char* Interp4Set::GetCmdName() const
{
  return ::GetCmdName();
}


/*!
 *
 */
bool Interp4Set::ExecCmd( MobileObj  *pMobObj, int  Socket) const
{
  Vector3D new_position = pMobObj->GetPositoin_m();
  new_position[0] = this->_Wsp_x;
  new_position[1] = this->_Wsp_y;
  pMobObj->SetPosition_m(new_position);

  pMobObj->SetAng_Roll_deg(this->_Kat_Ox);
  pMobObj->SetAng_Pitch_deg(this->_Kat_Oy);

  return true;
}


/*!
 *
 */
bool Interp4Set::ReadParams(std::istream& Strm_CmdsList)
{
  Strm_CmdsList >> _Wsp_x >> _Wsp_y >> _Kat_Ox >> _Kat_Oy;
  return !Strm_CmdsList.fail();
}


/*!
 *
 */
Interp4Command* Interp4Set::CreateCmd()
{
  return new Interp4Set();
}


/*!
 *
 */
void Interp4Set::PrintSyntax() const
{
  cout << "   Set  NazwaObiektu  pozycja_x[m]  pozycja_y[m]  kat_OX[deg]  kat_OY[deg] " << endl;
}
