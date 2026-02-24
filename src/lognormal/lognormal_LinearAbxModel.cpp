#include "lognormal/lognormal.h"

namespace lognormal{

LinearAbxModel::LinearAbxModel(int nst, int nmetro, int fw, int ch) : LogNormalModel(nst,0,nmetro,fw,ch)
{
    delete icp;
    icp = new LinearAbxICP(nst,nmetro);
}

} // namespace lognormal
