type state = {
	value: int
};

type action =
	| Increase
	| Decrease;

let component = ReasonReact.reducerComponent("Stepper");

let make = (children) => ({
	...component,
	initialState: () => {
		value: 0
	},
	reducer: (action, state) => {
		switch action {
		| Decrease => ReasonReact.Update({value: state.value - 1})
		| Increase => ReasonReact.Update({value: state.value + 1})
		};
	},
	render: (self) =>
			<div>
				<button onClick={self.reduce((evt) => Decrease)}>(ReasonReact.stringToElement(" - "))</button>
				<div>(ReasonReact.stringToElement(string_of_int(self.state.value)))</div>
				<button onClick={self.reduce((evt) => Increase)}>(ReasonReact.stringToElement(" + "))</button>
			</div>
});