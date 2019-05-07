#pragma once


namespace samples
{
	
	class ConstructorPr
	{
		
	public:
		float x, y;
		ConstructorPr() = delete;
		ConstructorPr(float x, float y);
		//void Init();
		void Print();
	};
}

