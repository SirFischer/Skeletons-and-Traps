#pragma once

namespace mf
{
    enum class eEvent
    {
        OUTSIDE,
        ENTERED,
        INSIDE,
        EXITED,
        LEFT_CLICK,
        RIGHT_CLICK,
        LEFT_CLICK_RELEASE,
        RIGHT_CLICK_RELEASE,
		FOCUS,
		LOST_FOCUS
    };
} // namespace mf
