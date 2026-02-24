#include "lognormal/lognormal.h"

namespace lognormal{

LinearAbxModel2::LinearAbxModel2(int nst, int nmetro, int fw, int ch) : LogNormalModel(nst,0,nmetro,fw,ch)
{
    delete icp;
    icp = new LinearAbxICP2(nst,nmetro);
}

} // namespace lognormal
