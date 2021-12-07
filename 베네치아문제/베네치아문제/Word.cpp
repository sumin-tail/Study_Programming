#include "Word.h"

void Word::draw()
{
	m_DrawInterface.TextDraw(m_word, m_x, m_y);
}

void Word::drop()
{

}
