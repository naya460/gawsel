import { MotionStyle, motion } from 'framer-motion'

export default function ClossFade(
	props: {
		children?: JSX.Element,
		style?: MotionStyle
	}
) {
	return (
		<motion.div
		  initial={{opacity: "0%"}}
		  animate={{opacity: "100%"}}
		  exit={{opacity: "0%"}}
      	  transition={{duration: 0.08}}
		  style={props.style}
		>
			{props.children}
		</motion.div>
	)
}