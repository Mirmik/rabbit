#ifndef RABBIT_PHYSICS_BODY_H
#define RABBIT_PHYSICS_BODY_H

namespace rabbit 
{
	struct body 
	{
		rabbit::htrans3 position; //< позиция тела в вычислительном базисе
		rabbit::inertia3 inertia; //< инерция тела в собственной системе.
		rabbit::himpulse3 impulse; //< h-импульс в вычислительном базисе.

		void integrate(T delta) 
		{
			auto locimpulse = impulse.trans(position.inverse());
			auto lochspd = locimpulse / inertia;
			auto hspd = lochspd.trans(position);

			position = position.integrate(hspd, delta);	
		} 

		void integrate(const hforce3<T>& force, T delta) 
		{
			impulse = impulse.integrate(force, delta);
			integrate(delta);
		}
	};
}

#endif