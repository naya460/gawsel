import { motion } from 'framer-motion'

export default function ClossFade(props: {children?: JSX.Element}) {
	return (
		<motion.div
		  initial={{opacity: "0%"}}
		  animate={{opacity: "100%"}}
		  exit={{opacity: "0%"}}
      transition={{duration: 0.08}}
		>
			{props.children}
		</motion.div>
	)
}