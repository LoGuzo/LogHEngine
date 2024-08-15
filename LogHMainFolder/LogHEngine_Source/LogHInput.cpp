#include "LogHInput.h"

namespace LogH
{
	vector<Input::Key> Input::mKeys = {};

	int ASCII[(int)E_KeyCode::End] =
	{
		'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P',
		'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L',
		'Z', 'X', 'C', 'V', 'B', 'N', 'M',
	};

	void Input::Initailize()
	{
		for (size_t i = 0; i < (UINT)E_KeyCode::End; i++)
		{
			Key key = {};
			key.bPressed = false;
			key.State = E_KeyState::None;
			key.KeyCode = (E_KeyCode)i;

			mKeys.push_back(key);
		}
	}
	void Input::Update()
	{
		for (size_t i = 0; i < mKeys.size(); i++)
		{
			// key pressed
			if (GetAsyncKeyState(ASCII[i]) & 0x8000)
			{
				if (mKeys[i].bPressed == true)
					mKeys[i].State = E_KeyState::Pressed;
				else
					mKeys[i].State = E_KeyState::Down;
				mKeys[i].bPressed = true;
			}
			else // key unpressed
			{
				if (mKeys[i].bPressed == true)
					mKeys[i].State = E_KeyState::Up;
				else 
					mKeys[i].State = E_KeyState::None;
				mKeys[i].bPressed = false;
			}
		}
	}
}