#ifndef ALUN_LOGNORMAL_MIXEDMODEL_H
#define ALUN_LOGNORMAL_MIXEDMODEL_H

#include "LogNormalModel.h"
#include "MixedICP.h"

class MixedModel : public LogNormalModel
{
public:

	MixedModel(int nst, int nmetro, int fw = 0, int ch = 0) : LogNormalModel(nst,nmetro,fw,ch)
	{
		delete icp;
		icp = new MixedICP(nst, 0,nmetro);
	}
};
#endif // ALUN_LOGNORMAL_MIXEDMODEL_H
