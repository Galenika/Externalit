#pragma once
#include "../../sdk/sdk.h"
namespace features {
	namespace misc {
		class cslowaim {
		public:
			cslowaim();
			void think();
		private:
			bool init;
			float old_sens;
		}; extern cslowaim* c_slowaim;
	}
}