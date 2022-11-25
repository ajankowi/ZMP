#include <iostream>
#include "Interp4Move.hh"
#include "MobileObj.hh"

using namespace std;


extern "C" {
 Interp4Command* CreateCmd(void);
  const char* GetCmdName() { return "Move"; }
}




/*!
 * \brief
 *
 *
 */
Interp4Command* CreateCmd(void)
{
  return Interp4Move::CreateCmd();
}


/*!
 *
 */
Interp4Move::Interp4Move(): _Speed_mmS(0), _Lenght(0)
{}


/*!
 *
 */
void Interp4Move::PrintCmd() const
{
  /*
   *  Tu trzeba napisać odpowiednio zmodyfikować kod poniżej.
   */
  cout << GetCmdName() << " " << _Speed_mmS  << " " << _Lenght << endl;
}


/*!
 *
 */
const char* Interp4Move::GetCmdName() const
{
  return ::GetCmdName();
}


/*!
 *
 */
bool Interp4Move::ExecCmd( MobileObj  *pMobObj,  int  Socket) const {

	int dire = 0;
	int iter = 0;

	if(this->_Speed_mmS > 0){
		dire = 1;
	}
	else{
		dire = -1;
	}


	for (int i = 0; i < iter; ++i){

		//pAccessCtrl->LockAccess();
	    Vector3D position = pMobObj->GetPositoin_m();
	    double angle = pMobObj->GetAng_Roll_deg();

	    position[0] += this->_Speed_mmS * dire * cos(M_PI * angle/180);
	    position[1] += this->_Speed_mmS * dire * sin(M_PI * angle/180);

	    pMobObj->SetPosition_m(position);
	    //pAccessCtrl->MarkChange();
	    //pAccessCtrl->UnlockAccess();
	    usleep(100000);

	}


	std::cout<<"Move DONE ";

  return true;
}


/*!
 *
 */
bool Interp4Move::ReadParams(std::istream& Strm_CmdsList)
{

	Strm_CmdsList >> _Speed_mmS >> _Lenght;

  return !Strm_CmdsList.fail();
}


/*!
 *
 */
Interp4Command* Interp4Move::CreateCmd()
{
  return new Interp4Move();
}


/*!
 *
 */
void Interp4Move::PrintSyntax() const
{
  cout << "   Move  NazwaObiektu  Szybkosc[m/s]  DlugoscDrogi[m]" << endl;
}
